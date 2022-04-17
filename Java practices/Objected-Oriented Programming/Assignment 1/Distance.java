package com.company;

public class  Distance {
    private String name;
    private double lat;
    private double lng;

    Distance(String name){
        Countries country = new Countries(name);
        this.name = country.getCountry();
        this.lat = Double.parseDouble(country.getLat());
        this.lng = Double.parseDouble(country.getLon());
    }
    public static String writeDistance(Distance a, Distance b){
        return "Country : "+a.name + "\nlatitude = "+a.lat+"\nlongitude = "+a.lng+"\n--------------------\n"+
                "Country : "+b.name + "\nlatitude = "+b.lat+"\nlongitude = "+b.lng+"\n--------------------\n";

    }
    public static String getDistance(Distance a, Distance b){
        double distance = Math.sqrt(Math.pow((a.lng - b.lng),2)+ Math.pow((a.lat-b.lat),2) );
        return Double.toString(distance);
    }
}
