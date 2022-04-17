package com.company;

class Professor implements Comparable<Professor>{
    String name;
    String department;
    int class_number;
    String id;
    Professor(String name, String dpt, String id, int cnum){
        this.name = name;
        this.department = dpt;
        this.class_number = cnum;
        this.id = id;
    }
    public String toString(){
        return "name: " + this.name +", department: "+ this.department + ", professor Id: "+ this.id + ", classNum: " + this.class_number;
    }

    @Override
    public int compareTo(Professor professor) {
        if(this.class_number == professor.class_number)
            return 0;
        else if(this.class_number > professor.class_number)
            return 1;
        else return -1;
    }
}
