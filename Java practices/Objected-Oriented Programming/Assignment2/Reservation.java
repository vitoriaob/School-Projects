package com.company;

class Reservation implements Comparable<Reservation>{
    int roomnum;
    String[] res = new String[15];
    // 2 indexes for each date, an array for each room

    Reservation(int roomnum, String[] res){
        this.roomnum = roomnum;
        this.res = res;
    }
    public void RoomAvailable(){
        String[] days = {"6/1오전", "6/1오후", "6/2오전", "6/2오후", "6/3오전", "6/3오후", "6/4오전","6/4오후", "6/5오전", "6/5오후", "6/6오전", "6/6오후", "6/7오전", "6/7오후"};
        String message = "가능한 시간: ";
        for(int i =0; i < this.res.length-1; i++){
            if(this.res[i + 1].equals("possible")){
                message += days[i];
                if(i < days.length-1) message += ", ";
            }
        }
        System.out.println(message);
    }
    public String toString(){
        String line1, line2;
        line1 = "오전: ";
        line2 = "오후: ";
        String[] days = {"6/1", "6/1", "6/2", "6/2", "6/3", "6/3", "6/4","6/4", "6/5", "6/5", "6/6", "6/6", "6/7", "6/7"};
        for(int i = 0; i< res.length -1; i++){
            if(i%2 == 1) {
                if(res[i+1].equals("possible")){
                    line2 += days[i] ;
                    if(i<days.length-1) line2+= ", ";
                }
            }
            else{
                if(res[i+1].equals("possible")){
                    line1+= days[i];
                    if(i<days.length-2) line1+= ", ";
                }
            }
        }
        return this.roomnum + "\n" + line1 + "\n"+ line2 ;
    }
    @Override
    public int compareTo(Reservation reservation) {
        if(this.roomnum == reservation.roomnum)
            return 0;
        else if(this.roomnum > reservation.roomnum)
            return 1;
        else return -1;
    }
}

