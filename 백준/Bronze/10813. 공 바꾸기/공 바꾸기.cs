using System;

namespace CodingTest
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            int n = Convert.ToInt32(input[0]);
            int m = Convert.ToInt32(input[1]);

            int[] arr = new int[n];

            for(int i = 0; i < n; i++)
            {
                arr[i] = i + 1;
            }

            for(int i = 0; i < m; i++)
            {
                string[] input2 = Console.ReadLine().Split();
                int a = Convert.ToInt32(input2[0]) - 1;
                int b = Convert.ToInt32(input2[1]) - 1;

                int temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
            }

            Console.WriteLine(string.Join(" ", arr));
        }
    }
}
