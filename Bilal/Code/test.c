#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



typedef struct 
{
    SDL_Surface* charset;
    int nbx,nby;
    int w,h;
} Charset;

int Charger(Charset* c,const char* fic,int nbx,int nby,Uint8 keycolorR,Uint8 keycolorG,Uint8 keycolorB)
{
    SDL_Surface* tmp = SDL_LoadBMP(fic);
    if (c==NULL)
        return -1;
    c->charset = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    SDL_SetColorKey(c->charset,SDL_SRCCOLORKEY,SDL_MapRGB(c->charset->format,keycolorR,keycolorG,keycolorB));
    c->nbx = nbx;
    c->nby = nby;
    c->w = c->charset->w/nbx;
    c->h = c->charset->h/nby;
    return 0;
}

void FreeCharset(Charset* c)
{
    SDL_FreeSurface(c->charset);
}

void CharsetGetSrcRect(Charset* C,SDL_Rect* src,int frame)
{
    src->w = (Uint16)C->w;
    src->h = (Uint16)C->h;
    src->x = (Sint16)((frame%C->nbx)*C->w);
    src->y = (Sint16)((frame/C->nbx)*C->h);
}

// --------- Animation

typedef struct
{
    int framedepart;
    int nbframes;
    int delay;
} Anim;

void SetAnim(Anim* A,int framedepart,int nbframes,int delay)
{
    A->framedepart = framedepart;
    A->nbframes = nbframes;
    A->delay = delay;
}

int AnimGetFrame(Anim* A)
{
    return A->framedepart + (SDL_GetTicks()/A->delay)%A->nbframes;
}

// --------------------- Sprite

#define SENS_HAUT 0
#define SENS_DROITE 1
#define SENS_BAS 2
#define SENS_GAUCHE 3

#define STAT_ARRET 0
#define STAT_MARCHE 1

typedef struct
{
    Charset* C;
    Anim A;
    SDL_Rect pos;
    int sens;
    int status;
} Sprite;

void SetSprite(Sprite* S,int x,int y,Charset* C,int framedepart)
{
    S->pos.x = (Sint16)x;
    S->pos.y = (Sint16)y;
    S->C = C;
    SetAnim(&S->A,framedepart,1,1);
    S->sens = SENS_HAUT;
    S->status = STAT_ARRET;
}

void RenderSprite(SDL_Surface* screen,Sprite* S)
{
    SDL_Rect src;
    int frame = AnimGetFrame(&S->A);
    CharsetGetSrcRect(S->C,&src,frame);
    SDL_BlitSurface(S->C->charset,&src,screen,&S->pos);
}

// ----------------- Fonctions

void Evolue(Sprite SP[2],Uint8 * keys,int startframeperso[2])
{
    int i,j;
    int control[2][4] = {{SDLK_UP,SDLK_RIGHT,SDLK_DOWN,SDLK_LEFT},{SDLK_i,SDLK_l,SDLK_k,SDLK_j}};
    Sint16 vec[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
    Sint16 speed = 2;
    int speedanim = 120;
    for(i=0;i<2;i++)
    {
        int move = 0;
        for(j=0;j<4;j++)
        {
            if (keys[control[i][j]])
            {
                move = 1;
                if (SP[i].status == STAT_ARRET || SP[i].sens != j)
                    SetAnim(&SP[i].A,startframeperso[i] + SP[i].C->nbx*j,3,speedanim);
                SP[i].sens = j;
                SP[i].pos.x+=speed*vec[j][0];
                SP[i].pos.y+=speed*vec[j][1];
                SP[i].status = STAT_MARCHE;
            }
        }
        if (SP[i].status == STAT_MARCHE && !move)
        {
            SetAnim(&SP[i].A,startframeperso[i] + SP[i].C->nbx*SP[i].sens + 1,1,1);
            SP[i].status = STAT_ARRET;
        }
    }
}

int main(int argc,char** argv)
{
    SDL_Surface* screen;
    Charset C;
    Sprite SP[2];
    Uint8 * keys;
    int numkeys;
    Uint32 timer,elapsed;
    int startframeperso[2] = {0,6};
    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(400,300,32,SDL_SWSURFACE|SDL_DOUBLEBUF);  
    if (Charger(&C,"charset.bmp",12,8,32,156,0)!=0)
    {
        SDL_Quit();
        printf("Echec chargement charset.bmp\n");
        return -1;
    }
    SetSprite(&SP[0],100,100,&C,startframeperso[0]+1);
    SetSprite(&SP[1],300,100,&C,startframeperso[1]+1);
    do 
    {
        timer = SDL_GetTicks();
        SDL_FillRect(screen,NULL,0);
        SDL_PumpEvents();
        keys = SDL_GetKeyState(&numkeys);
        Evolue(SP,keys,startframeperso);
        RenderSprite(screen,&SP[0]);
        RenderSprite(screen,&SP[1]);
        SDL_Flip(screen);
        elapsed = SDL_GetTicks() - timer;
        if (elapsed<20)
            SDL_Delay(20-elapsed);
    } while (!keys[SDLK_ESCAPE]);
    FreeCharset(&C);
    SDL_Quit();
    return 0;
}
