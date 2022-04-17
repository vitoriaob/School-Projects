package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Countries {
    private String country;
    private String lat;
    private String lng;

    Countries(String CountryName){
        String row;
        String[] info;
        int count =0 ;
        try {
            BufferedReader file = new BufferedReader(new FileReader("Countries.csv"));
            while ((row = file.readLine()) != null && count != -1){
                info = row.split(",");
                if (info[count].equals(CountryName)){
                    this.country = info[count];
                    this.lat = info[count+1];
                    this.lng = info[count+2];
                    count = -1;
                }
            }
            file.close();
        }catch(FileNotFoundException e){
            System.exit(0);
        } catch(IOException e){
            e.printStackTrace();
        }
    }

    public String getCountry(){
        return this.country;
    }
    public String getLat(){
        return this.lat;
    }
    public String getLon(){
        return this.lng;
    }
}
