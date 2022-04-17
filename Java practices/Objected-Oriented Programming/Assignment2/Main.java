package com.company;
import java.io.*;
import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;



public class Main {
    static Scanner scanner = new Scanner(System.in);

    // Initializing Reservation Array List
    static ArrayList<Reservation> reservations = new ArrayList<>();


    static void CreateReservations(){
        try {
            BufferedReader br = new BufferedReader(new FileReader("reservation.csv"));
            String line = "";
            line = br.readLine();
            while((line = br.readLine()) != null){
                String[] room = line.split(",");
                int roomnum = Integer.parseInt(room[0]);
                reservations.add(new Reservation(roomnum, room));
                Collections.sort(reservations);
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //Initializing Student Array List
    static ArrayList<Student> students = new ArrayList<>();

    static void CreateStudents(){
        try {
            BufferedReader br = new BufferedReader(new FileReader("student.csv"));
            String line2 = br.readLine();
            while((line2 = br.readLine()) != null){
                String[] student = line2.split(",");
                students.add(new Student(student[0], student[1], student[2], student[3]));
                Collections.sort(students);
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    //Initializing Student Array List
    static ArrayList<Professor> professors = new ArrayList<>();

    static void CreateProfessors(){
        try {
            BufferedReader br = new BufferedReader(new FileReader("professor.csv"));
            String line3 = br.readLine();
            while ((line3 = br.readLine()) != null) {
                String[] profs = line3.split(",");
                int classnum = Integer.parseInt(profs[3]);
                Professor tmp = new Professor(profs[0], profs[1], profs[2], classnum);
                professors.add(tmp);
                Collections.sort(professors);
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static int RoomSearch( int value){
        int index = 0;
        while( index < reservations.size() && reservations.get(index).roomnum != value ) index++;
        if(index >= reservations.size()) return -1;
        else return index;
    }
    public static int finddayindex(String day){
        String[] days = {"6/1오전", "6/1오후", "6/2오전", "6/2오후", "6/3오전", "6/3오후", "6/4오전","6/4오후", "6/5오전", "6/5오후", "6/6오전", "6/6오후", "6/7오전", "6/7오후"};
        int index = 0;
        while(index < days.length && days[index] != day ) index++;
        if(index < days.length) return index;
        else return -1;
    }

    public static void main(String[] args) {
	    reserveinfo ri = new reserveinfo();
        CreateReservations();
        CreateProfessors();
        CreateStudents();
        ri.run();
	    //info i = new info();
	    //i.run();
    }

    public static class reserveinfo{
        public void run() {
            System.out.println("[메뉴 선택1]");
            System.out.println("1. 전제 예약 현항 조회");
            System.out.println("2. 호실 예약 현항 조회");
            System.out.println("3. 예약하기 및 취소하기");
            System.out.println("4. 나의 예약 조회");
            System.out.println("5. 학생 인적사항 변경");
            System.out.println("6. 교수 인적사항 변경");
            System.out.println("7. 종료");
            int key;


            key = scanner.nextInt();

                switch (key) {
                    case 1:
                        System.out.println("[1.전제 예약 현항 조회]");
                        for (Reservation res : reservations) {
                            System.out.println(res);
                        }
                        break;
                    case 2:
                        System.out.println("[2.호실 예약 현항 조회]");
                        int value = scanner.nextInt();
                        int search = RoomSearch(value);
                        if (search > 0) reservations.get(search).RoomAvailable();
                        else System.out.println("없는 호실입니다.");

                        break;
                    case 3:
                        System.out.println("[3.예약하기 및 취소하기]");
                        System.out.println("1. 예약하기");
                        System.out.println("2. 취소하기");
                        int nextkey = scanner.nextInt();
                        if (nextkey == 1) {
                            System.out.println("이름, 아이디, 호실 번호, 시간, 사유 입력");

                            String[] inp = new String[5];
                            inp[0] = scanner.next();
                            inp[1] = scanner.next();
                            inp[2] = scanner.next();
                            inp[3] = scanner.next();
                            inp[4] = scanner.next();

                            try {

                                Scanner br2 = new Scanner(new File("reservation.csv"));
                                String[] lines2 = new String[50];
                                int y=0;
                                while (br2.hasNextLine()) {
                                    lines2[y] = br2.nextLine();
                                    y++;
                                }
                                br2.close();
                                Scanner br = new Scanner(new File("reservationRecord.csv"));
                                String[] lines = new String[50];
                                int i=0;
                                while (br.hasNextLine()) {
                                    lines[i] = br.nextLine();
                                    i++;
                                }
                                br.close();
                                BufferedWriter writer = new BufferedWriter(new FileWriter("reservationRecord.csv"));
                                BufferedWriter writer2 = new BufferedWriter(new FileWriter("reservationRecord.csv"));
                                int index1 = 0;
                                //Search name
                                while (index1 <= students.size() && !students.get(index1).name.equals(inp[0])) index1++;
                                if (index1 >= students.size()) throw new Exception("예약 실패!");
                                    //Check id
                                else if (!students.get(index1).ID.equals(inp[1])) throw new Exception("예약 실패!");
                                //Check room exists and is available
                                String[] room = inp[2].split("호");
                                int pos = finddayindex(inp[3]);
                                int searching = RoomSearch(Integer.parseInt(room[0]));
                                if (searching < 0 && !reservations.get(searching).res[pos].equals("possible"))
                                    throw new Exception("예약 실패!");

                                for(int x = 0; x < y; x++){
                                    String[] parse = lines2[x].split(",");
                                    if(parse[0].equals(room[0])){
                                        for(int h = 0; h < parse.length; h++){
                                            if(parse[h].equals(pos)){
                                                parse[h] = "impossible";
                                            }
                                            lines2[x]+=parse[h]+",";
                                        }
                                    }
                                }

                                for(int j = 0; j < y; j++){
                                    writer2.write(lines2[j]);
                                    writer2.write("\r\n");
                                }
                                for(int j = 0; j < i; j++){
                                    writer.write(lines[j]);
                                    writer.write("\r\n");
                                }
                                //writing
                                writer.write(inp[0] + "," + inp[1] + "," + inp[2] + "," + inp[3] + "," + inp[4] + "\n");
                              //  writer.write("\r\n");
                                writer.flush();
                                writer.close();
                                System.out.println(inp[2] + " " + inp[3] + "에 예약되었습니다.");


                            } catch (FileNotFoundException e) {
                                System.out.println(e.getMessage());
                            } catch (Exception e) {
                                System.out.println(e);
                            }


                        } else if (nextkey == 2) {
                            {
                                try {
                                    System.out.println("이름, 아이디, 호실 번호, 시간 입력");
                                    String[] inp = new String[4];
                                    inp[0] = scanner.next();
                                    inp[1] = scanner.next();
                                    inp[2] = scanner.next();
                                    inp[3] = scanner.next();

                                    Scanner br = new Scanner(new File("reservationRecord.csv"));
                                    String[] lines = new String[50];
                                    int i=0;
                                    while (br.hasNextLine()) {
                                        lines[i] = br.nextLine();
                                        i++;
                                    }
                                    br.close();
                                    BufferedWriter writer = new BufferedWriter(new FileWriter("reservationRecord.csv"));

                                    int index1 = 0;
                                    //Search name
                                    while (index1 < students.size() && !students.get(index1).name.equals(inp[0]))
                                        index1++;
                                    if (index1 >= students.size()) throw new Exception("취소 실패!");
                                        //Check id
                                    else if (!students.get(index1).ID.equals(inp[1])) throw new Exception("취소 실패!");
                                    //Check room exists and is available
                                    String[] room = inp[2].split("호");
                                    int pos = finddayindex(inp[3]);
                                    int searching = RoomSearch(Integer.parseInt(room[0]));
                                    if (searching < 0 && !reservations.get(searching).res[pos].equals("possible"))
                                        throw new Exception("예약 실패!");

                                    for(int j = 0; j < i; j++){
                                        String[] lista = lines[j].split(",");
                                        if (lista[0].equals(inp[0]) && lista[1].equals(inp[1]) && lista[2].equals(inp[2]) && lista[3].equals(inp[3])) {
                                            System.out.println(inp[2] + " " + inp[3] + " 예약이 취소되었습니다.");
                                        }else{
                                            writer.write(lines[j]);
                                            writer.write("\r\n");
                                            writer.flush();
                                        }

                                    }
                                    writer.close();
                                    br.close();


                                } catch (FileNotFoundException e) {
                                    System.out.println(e.getMessage());
                                } catch (Exception e) {
                                    System.out.println(e);
                                }
                            }
                        }

                        break;
                    case 4:
                        try {
                            System.out.println("[4. 나의 예약 조회]");
                            System.out.println("이름과 아이디(학번 또는 교직원 번호) 입력 ");
                            String name, id;
                            name = scanner.next();
                            id = scanner.next();

                            BufferedReader br = new BufferedReader(new FileReader("reservationRecord.csv"));
                            String compare = br.readLine();
                            int flag = 1;
                            while (compare != null) {
                                String[] lista = compare.split(",");
                                if (lista[0].equals(name) && lista[1].equals(id)) {
                                    flag = 0;
                                    System.out.println("이름: " + lista[0] + ", 아이디: " + lista[1] + ", 호실번호: " + lista[2] + ", 시간: " + lista[3] + ", 예약사유: " + lista[4]);
                                }
                                compare = br.readLine();
                            }
                            if (flag == 1) throw new Exception("없는 예약입니다. 이름과 아이디를 다시 확인해주세요.");
                            br.close();
                        } catch (FileNotFoundException e) {
                            System.out.println(e.getMessage());
                        } catch (Exception e) {
                            System.out.println(e);
                        }

                        break;
                    case 5:
                        System.out.println("[5. 학생 인적사항 변경]");
                        System.out.println("1. 인적사항 조회");
                        System.out.println("2. 이름 변경");
                        System.out.println("3. 학생 삭제");
                        int nextkey2 = scanner.nextInt();

                        if(nextkey2 == 1){
                            System.out.println("1. 인적사항 조회");
                            for(Student std : students){
                                System.out.println(std);
                            }
                        }
                        else if(nextkey2 == 2) {
                            System.out.println("2. 이름 변경");
                            String currname = scanner.next();
                            System.out.println("어떤 이름으로 변경하시겠습니까?");
                            String newname = scanner.next();
                            int flaggg = 0;
                            try {

                                Scanner br = new Scanner(new File("student.csv"));
                                String[] stds = new String[50];
                                int i=0;
                                while (br.hasNextLine()) {
                                    stds[i] = br.nextLine();
                                    i++;
                                }
                                br.close();
                                BufferedWriter writer = new BufferedWriter(new FileWriter("student.csv"));

                                for(int j = 0; j < i; j++) {
                                    String[] student = stds[j].split(",");
                                    if (student[0].equals(currname)) {
                                        String put_text = newname + ","+student[1]+","+student[2]+","+student[3];
                                        writer.write(put_text);
                                        writer.flush();
                                        flaggg = 1;
                                        System.out.println("이름 변경이 완료되었습니다.");

                                    }else{
                                        writer.write(stds[j]);
                                        writer.write("\r\n");
                                        writer.flush();
                                    }
                                }
                                writer.close();

                            } catch (FileNotFoundException e) {
                                System.out.println(e.getMessage());
                            } catch (IOException e) {
                                e.printStackTrace();
                            }



                            if (flaggg == 0) System.out.println("없는 이름입니다. 다시 확인해주세요.");
                        }

                        else if (nextkey2 == 3) {
                                System.out.println("3. 학생 삭제");
                                String name = scanner.next();
                                int flagggg = 0;
                                    try {

                                        Scanner br = new Scanner(new File("student.csv"));
                                        String[] lines = new String[50];
                                        int i=0;
                                        while (br.hasNextLine()) {
                                            lines[i] = br.nextLine();
                                            i++;
                                        }
                                        br.close();
                                        BufferedWriter writer = new BufferedWriter(new FileWriter("student.csv"));
                                        for(int j = 0; j<i; j++) {
                                            String[] student = lines[j].split(",");
                                            if(student[0].equals(name)) {
                                                System.out.println("삭제되었습니다.");
                                                flagggg = 1;
                                            }
                                            else{
                                                writer.write(lines[j]);
                                                writer.write("\r\n");
                                                writer.flush();
                                            }
                                        }
                                        br.close();
                                        writer.close();

                                    } catch (FileNotFoundException e) {
                                        System.out.println(e.getMessage());
                                    } catch (IOException e) {
                                        e.printStackTrace();
                                    }
                                if (flagggg == 0) System.out.println("없는 이름입니다. 다시 확인해주세요.");
                        }
                        break;
                    case 6:
                        System.out.println("[6. 교수 인적사항 조회]");
                        for(Professor prof : professors){
                            System.out.println(prof);
                        }
                        break;
                    case 7:
                        System.out.println("종료합니다.");
                        break;

                }

        }
    }
}
