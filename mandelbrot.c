#include <SDL.h>
#include <complex.h>

#define HEIGHT 100
#define WIDTH 100
#define MAX_ITER 25

int	mandelbrot(double complex c)
{
	double complex	z;
	int		i;

	z = 0;
	i = 0;
	while(i < 25)
	{
		z = z*z + c;
		if(cabs(z) > 2)
			return i;
		i++;
	}
	return -1;
}

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
	int		x;
	int		y;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError();
	if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &render) != 0)
		SDL_ExitWithError();
	
	program_launched = SDL_TRUE;
	while(program_launched)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;
				default:
					break;
			}
		}
		for(int x = 0; x < WIDTH; x++)
		{
			for(int y = 0; y < HEIGHT; y++)
			{
				double real = (x - WIDTH / 2) / (0.5 * WIDTH) + 0.5;
				double imag = (y - HEIGHT / 2) / (0.5 * HEIGHT);
				complex double c = real + imag * I;
				complex double z = 0;
				int iterations = 0;
				while(cabs(z) < 2 && iterations < MAX_ITER)	
				{
					z = z * z + c;
					iterations++;
				}
				if(iterations == MAX_ITER)
					SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
				else
				{
					int color = iterations % 8 * 32;
					SDL_SetRenderDrawColor(render, color, color, color, 255);
				}
				SDL_RenderDrawPoint(render, x, y);
			}
		}
	}

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
