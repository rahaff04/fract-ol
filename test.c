// #include <stdio.h>

// typedef struct s_complex
// {
//     double real;
//     double imag;
// } t_complex;

// int main ()
// {
//    t_complex z;
//    t_complex c;

//    double tempreal;

//    z.real = 0.0;
//     z.imag = 0.0;
//     c.real = 5;
//     c.imag = 2;
    
//     for (int i = 0; i < 42; i++)
//     {
//         tempreal = (z.real * z.real) - (z.imag * z.imag) ;
//         z.imag = 2 * z.real * z.imag ;
//         z.real = tempreal;
//         z.real += c.real;
//         z.imag += c.imag;
//         printf("Iteration %d: z = %.2f + %.2fi\n", i, z.real, z.imag);
//     }
// }