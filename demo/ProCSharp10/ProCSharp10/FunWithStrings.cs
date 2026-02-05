using System.Threading.Channels;

namespace CH3_ConstructsPart1;

public class FunWithStrings
{
    static void Main(string[] args)
    {
        //BasicStringFunctionality();
        StringComparisonFunc();
    }

    static void StringComparisonFunc()
    {
        string s1 = "Hello!";
        string s2 = "HELLO!";

        // 預設規則
        Console.WriteLine(s1.Equals(s2)); // false

        // 忽略大小寫
        Console.WriteLine(s1.Equals(s2, StringComparison.OrdinalIgnoreCase)); // true

        // 忽略大小寫，且不依文化
        Console.WriteLine(s1.Equals(s2, StringComparison.InvariantCultureIgnoreCase)); // true

        // IndexOf 也可以同樣控制
        Console.WriteLine(s1.IndexOf("E", StringComparison.OrdinalIgnoreCase)); // 1
    }

    static void BasicStringFunctionality()
    {
        Console.WriteLine("=> Basic String functionality:");
        string firstName = "Freddy";
        Console.WriteLine("Value of firstName: {0}", firstName);
        Console.WriteLine("firstName has {0} characters.", firstName.Length);
        Console.WriteLine("firstName in uppercase: {0}", firstName.ToUpper());
        Console.WriteLine("firstName in lowercase: {0}", firstName.ToLower());
        Console.WriteLine("firstName contains the letter y?: {0}",
            firstName.Contains("y"));
        Console.WriteLine("New first name: {0}", firstName.Replace("dy", ""));
        Console.WriteLine();
    }
}