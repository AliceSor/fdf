#include <mlx.h>
#include <stdlib.h>

int		key_hook(int kc, void *p)
{
	if (kc == 53)
		exit(0);
	return (0);
}

void	put_pixel(char *imdat, int ls)
{
	int *idat;

	idat = (int*)imdat;
	idat [0] = 0xFF00FF;
	idat [20*40 - 1] = 0xFF00FF;
}

int main(void)
{
	void	*mlx;
	void	*win;
	int		a;
	int		x;
	int		y;
	void	*im;
	int		bpss;
	int		ls;
	int		endian;
	char	*imdat;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "test");
	im = mlx_new_image(mlx, 20, 40);
	imdat = mlx_get_data_addr(im, &bpss, &ls, &endian);
	put_pixel(imdat, ls);
	mlx_put_image_to_window(mlx, win, im, 5, 5);
	mlx_key_hook(win, key_hook, 0);
	a = mlx_loop(mlx);

}
