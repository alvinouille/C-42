// void    gradient(t_data img, t_point pos, int end)
// {
//     int x = pos.x;
//     int color1 = 0x00FF0000;
//     unsigned char t1 = get_t(color1);
//     unsigned char r1 = get_r(color1);
//     unsigned char g1 = get_g(color1);
//     unsigned char b1 = get_b(color1);
//     int color2 = 0x00FFFFFF;
//     int t2 = get_t(color2);
//     int r2 = get_r(color2);
//     int g2 = get_g(color2);
//     int b2 = get_b(color2);
//     int color = 0;
//     int t0;
//     int r0;
//     int g0;
//     int b0;
//     int gradient = 100 / (end - x);
//     int t = 0;
//     while (x++ <= end)
//     {
//         color = (color1 * (1 - t) + (t * color2)) / 2;
//         img_pixel_put(&img, x, pos.y, create_trgb(0, r0, g0, b0));
//         t += gradient;
//         t0 = 0;
//         r0 = r1 * (100 - t)/100 + r2 * t;
//         g0 = g1 * (100 - t) + g2 * t;
//         b0 = b1 * (100 - t) + b2 * t;
//     }
// }

// int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
// {
// 	return (*(int *)(unsigned char [4]){b, g, r, t});
// }

// unsigned char	get_t(int trgb)
// {
// 	return (((unsigned char *)&trgb)[3]);
// }

// unsigned char	get_r(int trgb)
// {
// 	return (((unsigned char *)&trgb)[2]);
// }

// unsigned char	get_g(int trgb)
// {
// 	return (((unsigned char *)&trgb)[1]);
// }

// unsigned char	get_b(int trgb)
// {
// 	return (((unsigned char *)&trgb)[0]);
// }