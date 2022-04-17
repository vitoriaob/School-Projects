package com.company;

import java.util.StringTokenizer;


public class KeyValue {
    private String key;
    private String value;

    KeyValue(String line){
        StringTokenizer str = new StringTokenizer(line, "=");
        this.key = str.nextToken();
        this.value = str.nextToken();
    }

    KeyValue(String key, String value){
        this.key = key;
        this.value = value;
    }

    public String getKey(){
        return this.key;
    }
    public String getValue(){
        return this.value;
    }
}
