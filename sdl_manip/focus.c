#include <SDL.h>

#define WIN_HEIGHT 600
#define WIN_WIDTH 800

void	SDL_ExitWithError()
{
	SDL_Log("Error: %s.\n", SDL_GetError());
	SDL_Quit();
	exit(-1);
}

int	main()
{
	SDL_Window	*win;
	SDL_Renderer	*render;
	SDL_bool	program_launched;
	SDL_Event 	event;

	
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError();
	if(SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, 0, &win, &render) != 0)
		SDL_ExitWithError();

	program_launched = SDL_TRUE;
	while(program_launched)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_MOUSEMOTION:
					if(event.motion.x >= 799 || event.motion.x <= 0 || event.motion.y >= 599 || event.motion.y <= 0)
						printf("Bye!\n");
					else
						printf("Hi!\n");	
					break;
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;
				default:
					break;
			}
		}
	}

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
