using System;
using System.Runtime.InteropServices;

public class runme
{
  [DllImport("gcd.dll", EntryPoint="gcd")]
  public static extern int gcd(int a, int b);

  static void Main() 
  {
    // Call our gcd() function

    int x = 42;
    int y = 105;
    int g = gcd(x,y);
    Console.WriteLine("The gcd of " + x + " and " + y + " is " + g);
  }
}
