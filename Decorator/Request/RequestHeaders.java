
package Request;

import java.text.ParseException;
import java.util.HashMap;
import java.util.Map;

public class RequestHeaders {
    private Map<String, String> request_headers;
    
    public RequestHeaders()
    {
        request_headers=new HashMap<String, String>();
    }
    
    public void addHeader(String name, String value)
    {
        request_headers.put(name, value);
    }
    
    public void addHeader(String headerLine) throws ParseException
    {
        String[] parsed_header=parseHeader(headerLine);
        addHeader(parsed_header[0],parsed_header[1]);
    }
    
    private String[] parseHeader(String headerLine) throws ParseException {
        int colonIndex = headerLine.indexOf(':');
        if (colonIndex == -1 || colonIndex == 0 || colonIndex == headerLine.length() - 1) {
            throw new ParseException(String.format("Improperly formatted header: %s", headerLine),0);
        }
        return new String[]{headerLine.substring(0, colonIndex), 
            headerLine.substring(colonIndex + 1, headerLine.length()).trim()};
    }
    
    public Map<String, String> getHeaders()
    {
        return request_headers;
    }
}
