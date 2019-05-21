
package Response;

import java.util.HashMap;
import java.util.Map;

public class ResponseHeaders {

    private Map<String, String> response_headers;

    public ResponseHeaders() 
    {
        response_headers = new HashMap<String, String>();
    }
    
    public void addHeader(String name, String value)
    {
        response_headers.put(name, value);
    }
    
    public Map<String, String> getHeaders()
    {
        return response_headers;
    }
    
    @Override
    public String toString()
    {
        StringBuilder ret_str=new StringBuilder();
        response_headers.entrySet().forEach((res_header) -> {
            ret_str.append(res_header.getKey()).append(": ").append(res_header.getValue()).append("\r\n");
        });
        return ret_str.toString();
    }
}