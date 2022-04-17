package com.company;

import java.io.*;
import java.util.Calendar;
import java.util.StringTokenizer;

import static com.company.Distance.getDistance;
import static com.company.Distance.writeDistance;

public class TravelInfoRequest {

    public static void main(String[] args) {
        //setting the date string
        Calendar calendar = Calendar.getInstance();
        String date = calendar.get(Calendar.YEAR)+"-"+calendar.get(Calendar.MONTH)+"-"+calendar.get(Calendar.DAY_OF_MONTH);
        KeyValue day = new KeyValue("date", date);
        String line, tmp, dist;
        String reader;
        int count = 0;

        // ---------  reading the property file ---------- //
        try {
            BufferedReader file = new BufferedReader(new FileReader("properties.txt"));
            //first line: name
            line = file.readLine();
            KeyValue name = new KeyValue(line);
            //second line: inquiry
            line = file.readLine();
            KeyValue inquiry = new KeyValue(line);
            //third line: this party
            line = file.readLine();
            KeyValue thisparty = new KeyValue(line);
            //fourth line: start country
            line = file.readLine();
            KeyValue startCountry = new KeyValue(line);
            //fifth line: depart country
            line = file.readLine();
            KeyValue departCountry = new KeyValue(line);
            //sixth line: email
            line = file.readLine();
            KeyValue email = new KeyValue(line);

            file.close();

        // ------------ reading the template file and writing in the output file ------- //

            FileOutputStream fos = new FileOutputStream("output_fill.txt");
            OutputStreamWriter osw = new OutputStreamWriter(fos);
            BufferedReader template = new BufferedReader(new FileReader("template_file.txt"));
            //Copying the template to the output file
            reader = template.readLine();
            while (reader != null) {
                StringTokenizer str = new StringTokenizer(reader, "{} <>");
                //adjusting the format
                while(str.hasMoreElements()) {
                    tmp = str.nextToken();
                    if(tmp.equals(name.getKey())){
                        tmp = name.getValue();
                        osw.write(tmp + ' ');
                    }
                    else if(tmp.equals(day.getKey())){
                        tmp = day.getValue();
                        osw.write(tmp);
                    }
                    else if(tmp.equals(inquiry.getKey())){
                        tmp = inquiry.getValue();
                        osw.write(tmp + ' ');
                    }
                    else if(tmp.equals(thisparty.getKey())){
                        tmp = thisparty.getValue();
                        osw.write(tmp + ' ');
                    }
                    else if(tmp.equals(startCountry.getKey())){
                        tmp = startCountry.getValue();
                        osw.write(tmp + ' ');
                    }
                    else if(tmp.equals(departCountry.getKey())){
                        tmp = departCountry.getValue();
                        osw.write(tmp + ' ');
                    }
                    else if(tmp.equals(email.getKey())) {
                        if (count == 0){
                            osw.write(tmp + ' ');
                            count++;
                        }
                        else {
                            tmp = email.getValue();
                            osw.write(tmp);
                        }
                    }
                    else if(tmp.equals("add")){
                        //------ writing distance info -----///
                        Distance country1 = new Distance(startCountry.getValue());
                        Distance country2 = new Distance(departCountry.getValue());
                        dist = writeDistance(country1, country2);
                        osw.write("Distance of\n");
                        osw.write(dist);
                        osw.write("is\n");
                        osw.write(getDistance(country1, country2));
                        tmp = str.nextToken(); // discarding the other word
                    }
                   else{
                        osw.write(tmp + ' ');
                    }
                }
                reader = template.readLine();
                osw.write( "\n");
            }
            template.close(); // end of copying from template
            osw.close();
            fos.close();

        }catch (FileNotFoundException e){
            System.exit(0);
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}


