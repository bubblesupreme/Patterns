
package Request;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.text.ParseException;
import java.util.Map;

public class HttpRequest {
    private RequestLine req_line;
    private RequestHeaders req_headers;
    private RequestMessage req_msg;
    public HttpRequest(BufferedReader request) throws IOException, ParseException
    {
        req_line= new RequestLine(request.readLine());
        req_headers = new RequestHeaders();
        while(true) {
                String header_line= request.readLine();
                if(header_line == null || header_line.trim().length() == 0) {
                    break;
                }
                else
                {
                    req_headers.addHeader(header_line);
                }
            }
        if (checkMessage())
        {
            req_msg = new RequestMessage(new ByteArrayInputStream(request.readLine().getBytes()));
        }
        else
        {
            req_msg = new RequestMessage();
        }
    }
    
    private boolean checkMessage()
    {
        for (Map.Entry<String, String> req_header : 
                req_headers.getHeaders().entrySet())
        {
            if (req_header.getKey().equals("Content-Length") 
                    && req_header.getValue().equals("0"))
            {
                return true;
            }
        };
        return false;
    }
    
    public RequestLine getRequestLine()
    {
        return req_line;
    }
    
    public RequestHeaders getRequestHeaders()
    {
        return req_headers;
    }
    
    public RequestMessage getRequestMessage()
    {
        return req_msg;
    }
}
