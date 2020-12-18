using System;

namespace Q599
{
    class Program
    {
        static double[] calculate(double vx, double vy, double y0, double h)
        {
            double[] res = new double[2];
            double a = -5.0, b = vy, c = y0 - h;
            double delta = b * b - 4 * a * c;
            if (delta < 0)
            {
                res[0] = -1;
                res[1] = -1;
            }
            else if (delta == 0)
            {
                res[0] = (-b) / (2 * a);
                if (res[0] >= 0)
                    res[0] *= vx;
                res[1] = -1;
            }
            else
            {
                delta = Math.Sqrt(delta);
                res[0] = (-b + delta) / (2 * a);
                res[1] = (-b - delta) / (2 * a);
                if (res[0] >= 0)
                    res[0] *= vx;
                if (res[1] >= 0)
                    res[1] *= vx;
            }
            return res;
        }

        static void Main()
        {
            string[] line = Console.ReadLine().Split(' ');
            double vx, vy, y0, h;
            vx = double.Parse(line[0]);
            vy = double.Parse(line[1]);
            y0 = double.Parse(line[2]);
            h = double.Parse(line[3]);
            var res = calculate(vx, vy, y0, h);
            if (res[0] >= 0)
                Console.WriteLine(res[0].ToString("0.00"));
            if (res[1] >= 0)
                Console.WriteLine(res[1].ToString("0.00"));
            if (res[0] < 0 && res[1] < 0)
                Console.WriteLine("impossible");
        }
    }
}
