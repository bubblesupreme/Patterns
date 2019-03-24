package IOC;

import java.text.SimpleDateFormat;
import java.util.Date;

public class DataLogProvider implements ILogFormatProvider
{
    private final SimpleDateFormat  date;
    
    public DataLogProvider()
    {
        date = new SimpleDateFormat ();
        setDatePattern("[k:m:s]");
    }
    
    private void setDatePattern (String s)
    {
      date.applyPattern(s);
    }
    
    @Override
    public StringBuilder formatLog(StringBuilder str)
    {
        return str.append(date.format(new Date())).append('\n');
    }
}
