package IOC;

public class SimpleLogProvider implements ILogFormatProvider
{    
    public SimpleLogProvider()
    {}
  
    @Override
    public StringBuilder formatLog(StringBuilder str)
    {
        return str;
    }
}