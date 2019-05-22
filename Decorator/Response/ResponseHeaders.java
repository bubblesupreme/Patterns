
package Response;

import java.util.HashMap;
import java.util.Map;

public class ResponseHeaders {

    private Map<String, String> responseHeaders;

    public ResponseHeaders() 
    {
        responseHeaders = new HashMap<String, String>();
    }
    
    public void addHeader(String name, String value)
    {
        responseHeaders.put(name, value);
    }
    
    public Map<String, String> getHeaders()
    {
        return responseHeaders;
    }
    
    @Override
    public String toString()
    {
        StringBuilder ret_str=new StringBuilder();
        responseHeaders.entrySet().forEach((res_header) -> {
            ret_str.append(res_header.getKey()).append(": ").append(res_header.getValue()).append("\r\n");
        });
        return ret_str.toString();
    }
}