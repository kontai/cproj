//ShowEnvironmentDetails();

//DefaultDeclarations();
//CharFunctionality();


//DatetimeFuc();
TimeSteampFunc();


static void DatetimeFuc()
{
    DateTime dt = DateTime.Now;
    Console.WriteLine(dt);
    Console.WriteLine("day of year: {0}", dt.DayOfYear);

    DateTime dt2 = dt.AddDays(1);
    Console.WriteLine(dt2);

}

static void TimeSteampFunc()
{

    TimeSpan ts = new TimeSpan(4, 30, 0); // 4 小時 30 分鐘 0 秒
    Console.WriteLine(ts);

    // 減去 15 分鐘
    Console.WriteLine(ts.Subtract(new TimeSpan(0, 15, 0))); // 4:15:00
}

static void CharFunctionality()
{
    Console.WriteLine("=> char type Functionality:");
    char myChar = 'a';
    Console.WriteLine("char.IsDigit('a'): {0}", char.IsDigit(myChar));
    Console.WriteLine("char.IsLetter('a'): {0}", char.IsLetter(myChar));
    Console.WriteLine("char.IsWhiteSpace('Hello There', 5): {0}",
        char.IsWhiteSpace("Hello There", 5));
    Console.WriteLine("char.IsWhiteSpace('Hello There', 6): {0}",
        char.IsWhiteSpace("Hello There", 6));
    Console.WriteLine("char.IsPunctuation('?'): {0}",
        char.IsPunctuation('?'));
    Console.WriteLine();
}

void DefaultDeclarations()
{
    Console.WriteLine("=>Defualt Declarations:");
    int myInt = default;
    Console.WriteLine(myInt);
}

static void ShowEnvironmentDetails()
{
    // Print out the drives on this machine,
    // and other interesting details.
    foreach (string drive in Environment.GetLogicalDrives())
    {
        Console.WriteLine("Drive: {0}", drive);
    }

    Console.WriteLine("OS: {0}", Environment.OSVersion);
    Console.WriteLine("Number of processors: {0}",
        Environment.ProcessorCount);
    Console.WriteLine(".NET Core Version: {0}",
        Environment.Version);

    Console.WriteLine("Process Id: {0}", Environment.ProcessId);
}