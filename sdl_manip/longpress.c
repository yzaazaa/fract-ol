#include <SDL.h>
#include <stdio.h>

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
	Uint32		start;
	Uint32		end;
	int		isKeyPressed;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError();
	if(SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, 0, &win, &render) != 0)
		SDL_ExitWithError();

	program_launched = SDL_TRUE;
	isKeyPressed = 0;
	while(1)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_KEYDOWN:
					if(!isKeyPressed)
					{
						start = SDL_GetTicks();
						isKeyPressed = 1;
					}
					break;
				case SDL_KEYUP:
					end = SDL_GetTicks();
					if(end - start >= 5000)
						printf("Longpress!\n");
					isKeyPressed = 0;
					break;
				case SDL_QUIT:
					SDL_DestroyRenderer(render);
					SDL_DestroyWindow(win);
					SDL_Quit();
					return 0;
			}
		}
	}

	return (0);
}
