/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:10:22 by trupham           #+#    #+#             */
/*   Updated: 2025/06/16 15:21:52 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>   // For abs()

#define WIDTH 800
#define HEIGHT 600

mlx_image_t* g_img; // Global image pointer for simplicity in example

// Function to put a pixel on the image
// (You already have this, but defining it explicitly for clarity)
void put_pixel(mlx_image_t* img, unsigned int x, unsigned int y, int color)
{
    if (x < img->width && y < img->height)
        mlx_put_pixel(img, x, y, color);
}

// Bresenham's Line Algorithm implementation
void draw_line(mlx_image_t* img, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        put_pixel(img, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

int32_t main(void)
{
    mlx_t* mlx;

    mlx = mlx_init(WIDTH, HEIGHT, "MLX42 Bresenham Example", true);
    if (!mlx)
        exit(EXIT_FAILURE);

    g_img = mlx_new_image(mlx, WIDTH, HEIGHT); // Create image for the whole window
    if (!g_img)
    {
        mlx_terminate(mlx);
        exit(EXIT_FAILURE);
    }
    mlx_image_to_window(mlx, g_img, 0, 0); // Display the image

    // Now, let's draw some lines using the draw_line function
    // Connect the dots you previously placed:
    draw_line(g_img, 200, 200, 300, 300, 0xFFFFFFFF); // White line
    draw_line(g_img, 300, 300, 400, 400, 0x00FF00FF); // Green line

    // Draw some other lines to demonstrate
    draw_line(g_img, 50, 50, 750, 50, 0xFF0000FF);   // Horizontal Red Line
    draw_line(g_img, 50, 50, 50, 550, 0x0000FFFF);   // Vertical Blue Line
    draw_line(g_img, 100, 500, 700, 100, 0xFF00FFFF); // Magenta diagonal

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
