#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 600

int		mandelbrot(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = 0;
	while (iter < 100 && z_re2 + z_im2 < 4)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		iter++;
	}
	return (iter);
}

int		main(int argc, char **argv)
{
	SDL_Window	*window;
	SDL_Renderer	*renderer;
	SDL_Event	event;
	int		x;
	int		y;
	int		iter;
	double	c_re;
	double	c_im;
	SDL_bool	program_launched;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	window = SDL_CreateWindow("Mandelbrot", SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
							  SDL_WINDOW_SHOWN);
	if (!window)
	{
		fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
		return (1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
		return (1);
	}
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		c_im = (y - HEIGHT / 2) * 4.0 / HEIGHT;
		while (x < WIDTH)
		{
			c_re = (x - WIDTH / 2) * 4.0 / WIDTH;
			iter = mandelbrot(c_re, c_im);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, iter * 255 / 100);
			SDL_RenderDrawPoint(renderer, x, y);
			x++;
		}
		y++;
	}
	SDL_RenderPresent(renderer);
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
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}

