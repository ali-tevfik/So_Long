#include "so_long.h"

int *ciz(int kacinci)
{
    void *mlx;
    char *relative_path = "./teapot.xpm";
    int img_width, img_height;

    void *mlx_win;
    t_img img;

    if (kacinci == 1)
    {
        mlx = mlx_init();
        printf("\n\n\nmlx %s", (char *)mlx);
        mlx_win = mlx_new_window(mlx, 1280, 1280, "Hello world!");

        //img.img_ptr = mlx_init();
        img.img_ptr = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
        img.address = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_size,
                                        &img.endian);

        my_mlx_pixel_put(&img, 5, 5, 0x00FF00);
    }

    mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, kacinci * 63);
    return (mlx);
}