package com.company;

class Student implements Comparable<Student>{
    String name;
    String department;
    String ID;
    String phone;

    Student(String name, String dpt, String ID, String phone){
        this.name = name;
        this.ID = ID;
        this.department= dpt;
        this.phone = phone;
    }
    public String toString(){
        return "name: " + this.name +", department: "+ this.department + ", studentID: "+ this.ID + ", phoneNum: " + this.phone;
    }
    @Override
    public int compareTo(Student student) {
        if(this.name.equals(student.name))
            return 0;
        else if(this.name.compareTo(student.name) > 1)
            return 1;
        else return -1;
    }
}