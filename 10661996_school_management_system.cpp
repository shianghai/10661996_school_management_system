#include <iostream> 
#include <vector> 
#include <stdlib.h> 
#include <string> 
#include <sstream> 
#include <fstream> 
  
 
using namespace std; 
  
 
template <class var> 
  
 
void print(var textline){ 
  cout << textline; 
  } 
  
 
  
 
  /*  functions definitions */ 
  vector <string> split(string line, char by); 
  bool findStr(vector<string> _list, string key); 
  string multiStr(string val, int num), gradeCalc(double score); 
  void help(string command), listItems(string arrayVar[]), setItems(string val); 
  void _add(), _edit(), _remove(), _list(), _search(), _start(string s), exit(); 
  string choice(), engine(), inputStr(string show), getStr(string show), upper(string line), lower(string line); 
  int inputInt(string show);float inputFloat(string show);double inputDouble(string show);void printer(string val); 
  
 
  
 
  //structs 
  struct course { 
      int level; 
      string subjects[10]; 
  }; 
  
 
  struct Department { 
      string dep_code; 
      string dep_name; 
      course dep_courses[4]; 
  }; 
  
 
  struct record{ 
      int semester; 
      int credit_hr; 
      string course_name; 
      int mark; 
      string grade; 
  }; 
  
 
  //computerscience department.. 
  Department comp_science = { 
      "CSCD", 
      "Department Of Computer Science", 
      { 
       100, {"CSCD 101","CSCD 102","CSCD 103","CSCD 104","CSCD 105","CSCD 106","CSCD 107","CSCD 108","CSCD 109","CSCD 110"}, 
       200, {"CSCD 201","CSCD 202","CSCD 203","CSCD 204","CSCD 205","CSCD 206","CSCD 207","CSCD 208","CSCD 209","CSCD 210"}, 
       300, {"CSCD 301","CSCD 302","CSCD 303","CSCD 304","CSCD 305","CSCD 306","CSCD 307","CSCD 308","CSCD 309","CSCD 310"}, 
       400, {"CSCD 401","CSCD 402","CSCD 403","CSCD 404","CSCD 405","CSCD 406","CSCD 407","CSCD 408","CSCD 409","CSCD 410"}, 
      } 
  }; 
  
 
  vector <Department> DEPARTMENTS; 
  vector <string> DEP_CODES; 
  int helptips = 0; 
  int semester = 0; 
  int year; 
  
 
  
 
  
 
  class person 
  { 
      public: 
          person() 
          { 
              //set empty student name = "" 
              status = "null"; 
          } 
          //setter functions for student 
          void setName(string val){ 
              name = val; 
          } 
  
 
          void setStatus(string val){ 
              status = val; 
          } 
  
 
          void setAge(int val){ 
              age = val; 
          } 
  
 
          void setID(int val){ 
              object_id = val; 
          } 
  
 
          void setIndex(int val){ 
              index = val; 
          } 
  
 
          void setResidence(string val){ 
              residence = val; 
          } 
  
 
          void listItems(vector <string> arrayVar){ 
              int len = arrayVar.size(); 
              for (int i=0;i<len;i++){ 
                  print(arrayVar[i]); 
                  if ((i+1)%3 == 0){ 
                      print("\n"); 
                 }else{ 
                      print("\t\t"); 
                  } 
              } 
          } 
  
 
  
 
          //getter functions for student 
          string getName(){ 
              return name; 
          } 
  
 
          string getStatus(){ 
              return status; 
          } 
  
 
          int getAge(){ 
              return age; 
          } 
  
 
           string getResidence(){               return residence; 
          } 
  
 
          string getType(){ 
              return "person"; 
          } 
  
 
          int getID(){ 
              return object_id; 
          } 
  
 
          int getIndex(){ 
              return index; 
          } 
  
 
          void getInfo(){ 
              cout << "\nname       : " << getName() << "\nage        : " << getAge() << "\nperson ID    : " << getID() <<endl; 
          } 
  
 
          vector<string> getSubjects(){ 
              return subjects; 
          } 
 
 
          void listSubjects(){ 
              listItems(subjects); 
          } 
  
 
          vector<string> getRegCourses(){ 
              return registrable_courses; 
          } 
  
 
          void listRegCourses(){ 
              listItems(registrable_courses); 
          } 
  
 
          void setSubject(string val){ 
              //check if subject is legit in registrable then 
              subjects.push_back(val); 
          } 
  
 
         void removeSubject(string val){ 
              int len = subjects.size(); 
              for (int i=0;i<len;i++){ 
                  if (upper(subjects[i]) == upper(val)){ 
                      subjects.erase(subjects.begin()+i); 
                      print("\nSubject successfully removed..."); 
                      break; 
                  } 
                  if (i == len-1){ 
                      print("\ncant find subject index...\n"); 
                  } 
              } 
          } 
  
 
  
 
      protected: 
          string name; 
          int age; 
          int index; 
          int object_id; 
          string status; 
          string residence; 
          string department; 
          vector <string> subjects; 
          vector <string> registrable_courses; 
  }; 
  
 
  
 
  
 
  //Classes 
  class staff : public person{ 
      private: 
          string job; 
  
 
      public: 
          void setDepartment(string val){ 
              department = val; 
              setRegCourse(); 
          } 
  
 
          void setJob(string val){ 
              job = val; 
          } 
  
 
          string getDepartment(){ 
              string dep; 
              int dep_count = DEPARTMENTS.size(); 
              for (int i=0;i<dep_count;i++){ 
                  if (DEPARTMENTS[i].dep_code == department){ 
                      dep = DEPARTMENTS[i].dep_name; 
                  } 
              } 
              return dep; 
          } 
  
 
         string getJob(){ 
              return job; 
          } 
  
 
          string getType(){ 
              return "staff"; 
          } 
  
 
        void setRegCourse(){ 
              int dep_count = DEPARTMENTS.size(); 
              for (int i=0;i<dep_count;i++){ 
                  //check null pointer DEPARTMENTS[i] != nullptr 
				                    if (DEPARTMENTS[i].dep_code == department){ 
                      //setting department courses for student at a certain level 
                      for (int j=0;j<4;j++){ 
                          for (int k=0;k<10;k++){ 
                              try{ 
                                  //print(DEPARTMENTS[i].dep_courses[j].subjects[k]);print(" "); 
                                  registrable_courses.push_back(DEPARTMENTS[i].dep_courses[j].subjects[k]); 
                              } 
                              catch(...){ 
                                  break; 
                              } 
                          } 
                      } 
                  } 
              } 
          } 
  
 
          void getInfo(){ 
              cout <<"\n\nstaff id   : " << getID() <<"\nname       : " << getName() << "\nage        : " << getAge() << "\nstatus     : " << getStatus() << "\ndepartment : " << getDepartment() << endl 
                   << "job        : " << getJob() <<"\n"; 
          } 
  }; 
  
 
  class student : public person{ 
      private: 
          float schoolfees; 
          int level; 
          string course; 
          vector<record> semester_records; 
          vector<record> academic_records; 
  
 
      public: 
          void setDepartment(string val){ 
              //if DEP_CODES.find(val) 
              department = val; 
              setRegCourse(); 
			            } 
          void setCourse(string val){ 
              course = val; 
          } 
          void setLevel(int val){ 
              level = val; 
          } 
          void setSchfees(float val){ 
              schoolfees = val; 
          } 
          void paySchfees(float val){ 
              schoolfees -= val; 
          } 
          void addSchfees(float val){ 
              schoolfees += val; 
          } 
  
 
         void setSubject(string val){ 
		               record temp; 
              temp.semester = semester; 
              temp.course_name = val; 
              temp.mark = -1; 
              semester_records.push_back(temp); 
              subjects.push_back(temp.course_name); 
          } 
  
 
          void recordMark(int index, int credit_h, int score){ 
              string grade = gradeCalc(score); 
              semester_records[index].mark = score; 
              semester_records[index].grade = grade; 
              semester_records[index].credit_hr = credit_h; 
          } 
  
 
          vector<record> getSemRecords(){ 
              return semester_records; 
          } 
  
 
          vector<record> getAcaRecords(){ 
              return academic_records; 
          } 
  
 
          void moveSemester(){ 
              if (getStatus() == "active"){ 
                  if (semester  == 1){ 
                      if (getLevel() != 400){ 
                          setLevel(getLevel()+100); 
                      } 
                      else{ 
                          setStatus("completed");                       } 
                      age += 1; 
                  } 
                  int len = semester_records.size(); 
                  for (int i=0;i<len;i++){ 
                     academic_records.push_back(semester_records[i]); 
                  } 
                  subjects.clear(); 
                  semester_records.clear(); 
                  registrable_courses.clear(); 
                  setRegCourse(); 
              } 
          } 
  
 
          void refresh(){ 
              subjects.clear(); 
              registrable_courses.clear(); 
              setRegCourse(); 
          } 
		    
 
         //getter functions for student 
		           string getDepartment(){ 
              string dep; 
              int dep_count = DEPARTMENTS.size(); 
              for (int i=0;i<dep_count;i++){ 
                  if (DEPARTMENTS[i].dep_code == department){ 
                      dep = DEPARTMENTS[i].dep_name; 
                  } 
              } 
              return dep; 
          } 
  
 
          string getType(){ 
              return "student"; 
          } 
  
 
          string getCourse(){ 
              return course; 
          } 
  
 
          int getLevel(){ 
              return level; 
          } 
  
 
          float getSchfees(){ 
              return schoolfees; 
          } 
  
 
          void getInfo(){ 
              cout << "\n\nStudent ID : " << getID() <<"\nname       : " << getName() << "\nage        : " << getAge() << "\nstatus     : " << getStatus() << "\ndepartment : " << getDepartment() << "\noffering   : " << getCourse() << endl 
                   << "in level   : " << getLevel() << "\nschool fees left : GHC " << getSchfees() <<"\n"; 
          } 
  
 
          void setRegCourse(){ 
              int dep_count = DEPARTMENTS.size(); 
              for (int i=0;i<dep_count;i++){ 
                  //check null pointer DEPARTMENTS[i] != nullptr 
                  if (DEPARTMENTS[i].dep_code == department){ 
                      //setting department courses for student at a certain level 
                      for (int j=0;j<4;j++){ 
                          if (DEPARTMENTS[i].dep_courses[j].level == level){ 
                              for (int k=0;k<10;k++){ 
                                  try{ 
                                      //print(DEPARTMENTS[i].dep_courses[j].subjects[k]);print(" "); 
                                      registrable_courses.push_back(DEPARTMENTS[i].dep_courses[j].subjects[k]); 
                                  } 
                                  catch(...){ 
                                      break; 
                                } 
                              } 
                          } 
                      } 
                  } 
              } 
          } 
  
 
      void removeSubject(string val){ 
          int len = semester_records.size(); 
          for (int i=0;i<len;i++){ 
              if (upper(semester_records[i].course_name) == upper(val)){ 
                  semester_records.erase(semester_records.begin()+i); 
                  subjects.erase(subjects.begin()+i); 
                  printer("success"); 
                  break;               } 
              if (i == len-1){ 
                  printer("error"); 
              } 
         } 
     } 
  }; 
  
 
  
 
  //global variables 
  vector <student> Students; 
  vector <staff> Staffs; 
  int stu_ID = 10640000; 
  int sta_ID = 15640000; 
  
 
  int main(){ 
  
 
      DEP_CODES.push_back(comp_science.dep_code);DEPARTMENTS.push_back(comp_science); 
  
 
      //starting the engine 
      _start("new"); 
  
 
     return 0; 
  } 
  
 
  //######  functions  ###### 
  int inputInt(string show){ 
      cin.clear(); 
      if (show == ""){ 
         // 
      } 
      else if (show == "default"){ 
          print("Enter a value : "); 
      } 
      else{ 
          print(show); 
      } 
      int value; 
      cin >> value; 
      while (cin.fail()){ 
          cin.clear();cin.ignore(); 
          print("\n( invalid input )  enter number(s) : "); 
          cin >> value; 
      }; 
      return value; 
  } 
  
 
  string inputStr(string show){ 
      cin.clear(); 
      if (show == ""){ 
         // 
      } 
      else if (show == "default"){ 
          print("Enter a value : "); 
      } 
      else{ 
          print(show); 
      } 
      string value; 
      cin >> value; 
      return value; 
  } 
  
 
  
 
  string getStr(string show){ 
      cin.clear();//cin.ignore(); 
      if (show == ""){ 
         // 
      } 
      else if (show == "default"){ 
          print("Enter a value : "); 
      } 
      else{ 
          print(show); 
      } 
      string value; 
      getline(cin, value); 
      return value; 
  } 
  
 
  float inputFloat(string show){ 
      cin.clear(); 
      if (show == ""){ 
         // 
      } 
      else if (show == "default"){ 
          print("Enter a value : "); 
      } 
      else{ 
          print(show); 
      } 
      float value; 
      cin >> value; 
      while (cin.fail()){ 
          cin.clear();cin.ignore(); 
          print("\n( invalid input )  enter number(s) : "); 
          cin >> value; 
      }; 
      return value; 
  } 
  
 
  double inputDouble(string show){ 
      cin.clear(); 
      if (show == ""){ 
         // 
      } 
      else if (show == "default"){ 
          print("Enter a value : "); 
      } 
      else{ 
          print(show); 
      } 
      double value; 
      cin >> value; 
      while (cin.fail()){ 
          cin.clear();cin.ignore(); 
          print("\n( invalid input )  enter number(s) : "); 
          cin >> value; 
      }; 
      return value; 
  } 
  
 
  
 
  string lower(string line){ 
      string LOWER = "abcdefghijklmnopqrstuvwxyz"; 
      string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
      string ret_lower = ""; 
      int len = line.length(); 
      for (int i=0;i<len;i++){//boy 
          for (int j=0;j<26;j++){ 
              if (line[i] == UPPER[j]){ 
                  ret_lower += LOWER[j]; 
                  break; 
              } 
              else if (j == 25){ 
                  ret_lower += line[i]; 
             } 
          } 
  
 
      } 
      return ret_lower; 
  } 
  
 
 
  string upper(string line){ 
      string ret_upper = ""; 
      int len = line.length(); 
      string LOWER = "abcdefghijklmnopqrstuvwxyz"; 
      string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
      for (int i=0;i<len;i++){ 
          for (int j=0;j<26;j++){ 
              if (line[i] == LOWER[j]){ 
                  ret_upper += UPPER[j]; 
                  break; 
              } 
              else if (j == 25){ 
                  ret_upper += line[i]; 
              } 
          } 
      } 
      return ret_upper; 
  } 
  
 
  
 
  bool isSpace(string line){ 
      int len = line.length(); 
      for (int i=0;i<len;i++){          
	   if (line[i] != ' '){ 
	                return false; 
          } 
      } 
      return true; 
  } 
  
 
  
 
  vector <string> split(string line, char by){ 
      string str = ""; 
      vector <string> splitVec; 
      int len = line.length(); 
      for (int i=0;i<len;i++){ 
          char _line = line[i]; 
          if (_line == by){ 
              splitVec.push_back(str); 
              str = ""; 
          } 
          else if (i+1 == len){ 
              str += line[i]; 
              splitVec.push_back(str); 
              str = ""; 
          } 
          else{ 
              str += line[i]; 
          } 
      } 
      return splitVec; 
  } 
  
 
  bool findStr(vector<string> _list, string key){ 
      int len = _list.size(); 
      for (int i=0;i<len;i++){ 
          if (lower(_list[i]) == lower(key)){               return true; 
          } 
      } 
      return false; 
  } 
  
 
  bool findStr(string subjs[], int length, string key){ 
      for (int i=0;i<length;i++){ 
          try{ 
              if (lower(subjs[i]) == lower(key)){ 
                  return true; 
              } 
          } 
          catch(...){ 
              break; 
          } 
      } 
      return false; 
  } 
  
 
  
 
  string multiStr(string val, int num){ 
      string longstr = ""; 
      for(int i=0;i<num;i++){ 
          longstr += val; 
      } 
      return longstr; 
  } 
  
 
  
 
  void listItems(vector <string> arrayVar){ 
      int len = arrayVar.size(); 
      for (int i=0;i<len;i++){ 
          print(arrayVar[i]); 
          if ((i+1)%3 == 0){ 
              print("\n"); 
          }else{ 
              print("\t\t"); 
         } 
      } 
  } 
  
 
  
 
  string gradeCalc(double score){ 
      if (79 < score && score <= 100){ 
          return "A"; 
      } 
      else if(74 < score && score <= 79){ 
          return "B+"; 
      } 
      else if(69 < score && score <= 74){ 
          return "B"; 
      } 
      else if(64 < score && score <= 69){ 
          return "C+"; 
      } 
      else if(59 < score && score <= 64){ 
          return "C"; 
      }       
	  else if(54 < score && score <= 59){ 
          return "D+"; 
      } 
      else if(49 < score && score <= 54){ 
          return "D"; 
      } 
      else if(44 < score && score <= 49){ 
          return "E"; 
      } 
      else if(-1 < score && score <= 44){ 
          return "F"; 
      } 
      else{ 
          return "invalid mark"; 
      } 
  } 
  
 
  
 
  void printer(string val){ 
      if (val == "start"){ 
          cout 
           << "##################################################################################################################" << endl 
           << "###############                                                                        ###########################" << endl 
           << "###############   ######  ######  ##    ##       ######   #######  #######  ##  ###    ###########################" << endl 
           << "###############   ##      ##      ##    ##       ##   ##  ##   ##  ##   ##  ##  ##     ###########################" << endl 
           << "###############   ##      ##      ##    ##       ##   ##  ##   ##  ##   ##  ####       ###########################" << endl 
           << "###############   ######  ##      ########       ######   ##   ##  ##   ##  ####       ###########################" << endl 
           << "###############       ##  ##      ##    ##       ##   ##  ##   ##  ##   ##  ##  ##     ###########################" << endl 
           << "###############       ##  ##      ##    ##  ###  ##   ##  ##   ##  ##   ##  ##   ##    ###########################" << endl 
          << "###############   ######  ######  ##    ##  ###  ######   #######  #######  ##   ###   ###########################" << endl 
           << "###############                                                                        ###########################" << endl 
           << "##################################################################################################################" << endl 
           << "###############     USE the keyword 'commands' to view available command options.      ###########################" << endl 
		   <<"################################  APP BY: FRANCIS SHIANGAH 10661996  ##############################################\n"<<endl;
      } 
      else if (val == "commands"){ 
        cout<<"\n\n##################################################################################################################\n"; 
          print("##\t Command              -----------------------------                Function\t\t\t\t##\n"); 
          print("##\t ============================================================================================= \t\t##\n"); 
          print("##\t q                    -----------------------------    use 'q' to leave any command center.....\t\t##\n"); 
          print("##\t add                  -----------------------------    create new student, dep. or staff.......\t\t##\n"); 
          print("##\t exit                 -----------------------------    end the program.........................\t\t##\n"); 
          print("##\t list                 -----------------------------    query list student, dep. or staff.......\t\t##\n"); 
          print("##\t edit                 -----------------------------    change student, dep. or staff details...\t\t##\n"); 
          print("##\t done                 -----------------------------    to save changes made to any object......\t\t##\n"); 
          print("##\t clear                -----------------------------    reset the screen to a clean screen......\t\t##\n"); 
          print("##\t search               -----------------------------    look for student, dep. or staff info....\t\t##\n"); 
          print("##\t remove               -----------------------------    delete staff, department or student.....\t\t##\n"); 
          print("##\t readme               -----------------------------    shows documentation of the app..........\t\t##\n"); 
          print("##\t help\\h               -----------------------------    get help with commands..................\t\t##\n"); 
          print("##\t manage               -----------------------------    pay or set student school fees etc .....\t\t##\n"); 
          print("##\t records              -----------------------------    record or view student academic records.\t\t##\n"); 
          print("##\t settings             -----------------------------    set app variables, turn off help tips...\t\t##\n"); 
          print("##################################################################################################################\n\n"); 
      } 
      else if (val == "y/n"){ 
          print("\n##################################################################################################################\n"); 
          print("###################################### invalid choice..please enter ( y/n ) ######################################\n"); 
          print("##################################################################################################################\n"); 
          print("\t\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "invh"){ 
          print("\n\n############################################################################################"); 
          print("\n##                     invalid command..use 'help' or 'h' for tips.                       ##"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "invcm"){ 
          print("\n\n############################################################################################"); 
          print("\n##                  invalid command method..please enter a valid command.                 ##"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "sb"){ 
          print("\n\n############################################################################################"); 
          print("\n##                        you can search object by 'id' or 'name'                         ##"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "invsb"){ 
          print("\n\n############################################################################################"); 
          print("\n##                    invalid search method..please enter 'id', 'name                     ##"); 
          print("\n############################################################################################"); 
      } 
	        else if (val == "invid"){ 
          print("\n\n############################################################################################"); 
          print("\n##              the ID you entered is invalid!...please check and try again.              ##"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "careful"){ 
          print("\n\n############################################################################################"); 
          print("\n##***************************#*#*# Enter Details Carefully.. #*#*#************************##"); 
          print("\n############################################################################################\n"); 
      } 
      else if (val == "removed"){ 
          print("\n\n############################################################################################"); 
          print("\n##***********************#*#*# This Student Has Been Removed.. #*#*#**********************##"); 
          print("\n############################################################################################\n"); 
      } 
      else if (val == "helptips"){ 
          print("\n##################################################################################################################\n"); 
          print("###############################   Do you want help tips at every route? (y/n)   ##################################\n"); 
          print("##################################################################################################################\n"); 
          print("\t\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "addmore"){ 
          print("\n\n##################################################################################################################\n"); 
          print("####################################    Do you want to add again? (y/n).     #####################################\n"); 
          print("##################################################################################################################\n"); 
          print("\t\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "choice"){ 
          print("\n\n##################################################################################################################\n"); 
          print("################################     Are you sure you want to proceed? (y/n).     ################################\n"); 
          print("##################################################################################################################\n"); 
          print("\t\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "explore"){ 
          print("\n\n######################################################################################################"); 
		            print("\n##     you can now search the found objects details...use 'help' to get more info on how to use.    ##"); 
          print("\n######################################################################################################"); 
      } 
      else if (val == "error"){ 
          print("\n\n############################################################################################"); 
          print("\n#############*****************#*#*#      ERROR!!!      #*#*#******************##############"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "found"){ 
          print("\n\n############################################################################################"); 
          print("\n#############*****************#*#*#    Found Object    #*#*#******************##############"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "movesem"){ 
          print("\n\n############################################################################################"); 
          print("\n#######*****#*#  please set students school fees and subjects for next sem.  #*#*****#######"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "success"){ 
          print("\n\n############################################################################################"); 
          print("\n#############******************#*#*#   Successful :-)   #*#*#*****************##############"); 
          print("\n############################################################################################"); 
      } 
	        else if (val == "saved"){ 
          print("\n\n############################################################################################"); 
          print("\n#############*******************#   Successfully Saved.    #******************##############"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "ignored"){ 
          print("\n\n############################################################################################"); 
          print("\n#############***************#*#*#    No Changes Made.     #*#*#***************##############"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "cantfind"){ 
          print("\n\n############################################################################################"); 
          print("\n##              Cannot find object...please check detail and search again.                ##"); 
          print("\n############################################################################################"); 
      } 
      else if (val == "enterid"){ 
          print("\n\n############################################################################################"); 
          print("\n##                                   Please Enter The ID                                  ##"); 
          print("\n############################################################################################"); 
          print("\n\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "entername"){ 
         print("\n\n############################################################################################"); 
          print("\n##                                  Please Enter The Name                                 ##"); 
          print("\n############################################################################################"); 
          print("\n\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "activate"){ 
         print("\n\n############################################################################################"); 
          print("\n##                         Do yo want to Activate Student? (y/n)                          ##"); 
          print("\n############################################################################################"); 
          print("\n\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "chol"){ 
          print("\n\n############################################################################################"); 
          print("\n##                            choose from the following list                              ##"); 
          print("\n############################################################################################\n\n"); 
      } 
      else if (val == "dchol"){ 
          print("\n\n############################################################################################"); 
          print("\n##                        do not choose from the following list                           ##"); 
          print("\n############################################################################################\n\n"); 
      } 
      else if (val == "welcome"){ 
          print("\n##################################################################################################################\n");
		            print("################***********#*#*#    Welcome...Please set the year and semester    #*#*#************###############\n"); 
          print("##################################################################################################################\n"); 
      } 
      else if (val == "enty"){ 
          print("\n##################################################################################################################\n"); 
          print("######################################### Enter the year eg. ( 2018 ) ############################################\n"); 
          print("##################################################################################################################\n"); 
          print("\t\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "inventy"){ 
          print("\n##################################################################################################################\n"); 
          print("########################################### Enter the year ( > 2017 ) ############################################\n"); 
          print("##################################################################################################################\n"); 
          print("\t\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "ents"){ 
          print("\n##################################################################################################################\n"); 
          print("######################################### Enter the Semester ( '1'/'2' ) #########################################\n"); 
          print("##################################################################################################################\n"); 
          print("\t\t\t\t\t\t['-'] : "); 
      } 
      else if (val == "exit"){ 
          print("\n##################################################################################################################\n"); 
          print("################################# Are you sure you want to quit the program ( y/n ) ##############################\n"); 
          print("##################################################################################################################\n"); 
          print("\t\t\t\t\t\t['-'] : "); 
		        } 
      else if (val == "help"){ 
          print("\n##################################################################################################################\n"); 
          print("##############################      Enter the [command] name for information.      ###############################\n"); 
          print("#####################################  Use help 'all' for all help tips. #########################################\n"); 
          print("##################################################################################################################\n"); 
  
 
      } 
      else{ 
          print("\nprinter : error!!!\n"); 
      } 
  } 
  
 
  
 
  void help(string command){ 
      command = lower(command); 
      if(command == ""){ 
          cin.clear(); 
          print("\n\nHelp >> "); 
          command = lower(inputStr("")); 
		    } 
      if (command == "exit"){ 
          print("\n\n############################################################################################"); 
          print("\n##              use 'exit' as command CHOOSE 'y' to exit or 'n' to continue               ##"); 
          print("\n############################################################################################ "); 
      } 
      else if (command == "help" || command == "h"){ 
          print("\n\n############################################################################################");           print("\n##      use 'help' [command] e.g. help all , help edit or [command] 'h' e.g. search h     ##"); 
          print("\n############################################################################################");       } 
      else if (command == "add"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO ADD NEW STUDENT......: use option 's' or 'student'                                 ##"); 
          print("\n##  [option] [firstname] [lastname] [othername] [age] [level] [Department Code] [course]  ##"); 
          print("\n############################################################################################ ");           print("\n##  TO ADD NEW STAFF........: use 'l' or 'staff'                                          ##"); 
          print("\n##  [option] [firstname] [lastname] [othername] [age] [Department Code]                   ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO ADD NEW DEPARTMENT...: use 'd' or 'department'                                     ##"); 
          print("\n##  [option] [Department Code] [Department Name]                                          ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "list"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO LIST STUDENT......: use option 's' or 'student'                                    ##"); 
          print("\n##  [option] [by] 'all', 'level', 'dep' [department code], 'residence' [residence name]   ##"); 
          print("\n############################################################################################ "); 
          print("\n##  TO LIST STAFF........: use 'l' or 'staff'                                             ##"); 
          print("\n##  [option] [by] 'all' , 'dep' [department code] , 'residence' [residence name]          ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO LIST DEPARTMENT...: use 'd' or 'department'                                        ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "search"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO SEARCH STUDENT......: use option 's' or 'student'                                  ##"); 
          print("\n##  [option] 'id' [student id] or [option] 'name' [student firstname and lastname]        ##"); 
          print("\n############################################################################################ "); 
          print("\n##  TO SEARCH STAFF........: use 'l' or 'staff'                                           ##"); 
          print("\n##  [option] 'id' [staff id] or [option] 'name' [staff firstname and lastname]            ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO SEARCH DEPARTMENT...: use 'd' or 'department'                                      ##"); 
          print("\n##  [option] [Department Code]   e.g. search d [cscd/MATHS].. list dep_code with 'ldc'    ##"); 
          print("\n############################################################################################"); 
          print("\n##  with GOTO..............: use 'explore' or 'edit' or 'remove' or 'academics            ##"); 
          print("\n##  e.g. Route Goto >> explore .. Goto >> edit ... Goto >> remove ...Goto >> academics    ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "explorestudent"){ 
          print("\n\n############################################################################################"); 
          print("\n#############################   USE the following keywords   ###############################"); 
          print("\n##**********                    'reg_subj' or 'reg_subjects'                 *************##"); 
          print("\n##                        'info' , 'name', 'age', 'level','residence'                     ##"); 
          print("\n##                       'course', 'status', dep', 'subj' or 'subjects'                   ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "explorestaff"){ 
          print("\n\n############################################################################################"); 
          print("\n#############################   USE the following keywords   ###############################"); 
          print("\n##**********                 'name', 'age', 'job', 'residence'               *************##"); 
          print("\n##                          'status', dep', 'subj' or 'subjects'                          ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "editstudent"){ 
          print("\n\n############################################################################################"); 
          print("\n#############################   USE the following keywords   ###############################"); 
          print("\n##**********               'name', 'age', 'level', 'residence'               *************##"); 
          print("\n##                   'course', 'status', dep', 'subj' or 'subjects'                       ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "editstaff"){ 
          print("\n\n############################################################################################"); 
          print("\n#############################   USE the following keywords   ###############################"); 
          print("\n##**********                       'name', 'age', 'job',                     *************##"); 
          print("\n##                       'residence', 'dep', 'subj' or 'subjects'                         ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "exploredep"){ 
          print("\n\n############################################################################################"); 
          print("\n#############################   USE the following keywords   ###############################"); 
          print("\n##**********                     'code', 'name', 'subject'                   *************##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "remove"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO REMOVE STUDENT......: use option 's' or 'student'                                  ##"); 
          print("\n##  [option] 'id' [student id] or [option] 'name' [student firstname and/or lastname]     ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO REMOVE STAFF........: use option 'l' or 'staff'                                    ##"); 
          print("\n##  [option] 'id' [staff id] or [option] 'name' [staff firstname and/or lastname]         ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO REMOVE DEPARTMENT...: use 'd' or 'department'                                      ##"); 
          print("\n##  [option] [Department Code]   e.g. remove d [cscd/MATHS].. list dep_code with 'ldc'    ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO SAVE EDITED DETAILS......................: use 'done' or use 'q' ot ignore changes ##"); 
          print("\n############################################################################################"); 
          print("\n##          search obj with [search] command first then enter 'remove' at Goto..          ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "edit"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO EDIT STUDENT........: use option 's' or 'student'                                  ##"); 
          print("\n##  [option] 'id' [student id] or [option] 'name' [student firstname and/or lastname]     ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO EDIT STAFF..........: use option 'l' or 'staff'                                    ##"); 
          print("\n##  [option] 'id' [staff id] or [option] 'name' [staff firstname and/or lastname]         ##"); 
		            print("\n############################################################################################"); 
          print("\n##  TO EDIT DEPARTMENT.....: use 'd' or 'department'                                      ##"); 
          print("\n##  [option] [Department Code]   e.g. edit d [cscd/MATHS].. list dep_code with 'ldc'      ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO SAVE EDITED DETAILS......................: use 'done' or use 'q' ot ignore changes ##"); 
          print("\n############################################################################################"); 
          print("\n############################################################################################"); 
          print("\n##          search obj with [search] command first then enter 'edit' at Goto..            ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "arsubject"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO ADD SUBJECTS.........: use option 'add' or 'a'                                     ##"); 
          print("\n##  [option] ['main' or 'm'|| 'free' or 'f'] [full subject name]                          ##"); 
          print("\n############################################################################################ "); 
          print("\n##  TO REMOVE SUBJECTS......: use option 'remove' or 'r'                                  ##"); 
          print("\n##  [option] [enter subject from list] [y or n]                                           ##"); 
          print("\n############################################################################################"); 
          print("\n##  USE the exact Subjects names from the list...                                         ##"); 
          print("\n##  eg.. CSCD 201 or cscd 201 or FE-CHEM 201                                              ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO SAVE EDITED DETAILS......................: use 'done' or use 'q' ot ignore changes ##"); 
          print("\n############################################################################################S"); 
      } 
	        else if (command == "showrecords"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO VIEW FULL STUDENT ACADEMIC RECOREDS..........: use option 'full' or 'f'            ##"); 
          print("\n############################################################################################ "); 
          print("\n##  TO VIEW SEMESTER STUDENT ACADEMIC RECOREDS......: use option 'sem' or 's'             ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO EXPORT STUDENT RECORDS.......................: use option 'exp' or 'e'             ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO CHECK STUDENT GPA............................: use the option 'gpa'                ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "records"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO ENTER STUDENT ACADEMIC RECOREDS..........: use option 'entry' or 'en'              ##"); 
          print("\n############################################################################################ "); 
          print("\n##  TO EDIT STUDENT ACADEMIC RECOREDS...........: use option 'edit' or 'ed'               ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO SHOW STUDENT ACADEMIC RECORDS............: use option 'show' or 's'                ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO SAVE EDITED DETAILS......................: use 'done' or use 'q' ot ignore changes ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "routes"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO EDIT DETAILS ......................: use the option 'edit'                         ##"); 
          print("\n############################################################################################ "); 
          print("\n##  TO EXPLORE DETIALS ...................: use the option 'explore'                      ##"); 
          print("\n############################################################################################"); 
		            print("\n##  TO MANAGE OBJECT......................: use the option 'manage'                       ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO GOTO STUDENT ACADEMIC RECORDS......: use the option 'records'   (student's only)   ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "manage"){ 
          print("\n\n############################################################################################"); 
          print("\n##  USE 'pay' or 'p' if student wants to pay SCHOOL FEES                                  ##"); 
          print("\n############################################################################################"); 
          print("\n##  USE 'add' or 'a'  to add SCHOOL FEES ..::Adds the amount to the students schoolfees   ##"); 
          print("\n############################################################################################"); 
          print("\n##  USE 'set' or 's'  to set SCHOOL FEES ..::reset the student school fees to the amount  ##"); 
          print("\n############################################################################################"); 
          print("\n##  USE 'remove' or 'r'  to REMOVE OBJECT..::removes (student or staff) object            ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO SAVE EDITED DETAILS......................: use 'done' or use 'q' ot ignore changes ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "settings"){ 
          print("\n\n############################################################################################"); 
          print("\n##  USE 'tips' or 't'      ........: to TURN OFF HELP TIPS AT ROUTES                      ##"); 
          print("\n############################################################################################"); 
          print("\n##  USE 'start' or 's'     ........: to RESET ACADEMIC CALLENDER                          ##"); 
          print("\n############################################################################################ "); 
          print("\n##  USE 'wipe' or 'w'      ........: to CLEAR OBJECTS AND RESET APP                       ##"); 
          print("\n############################################################################################"); 
          print("\n##  USE 'nextsem' or 'n'   ........: to MOVE STUDENT OBJECTS TO NEXT SEMESTER             ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "find"){ 
          print("\n\n############################################################################################"); 
          print("\n##  TO FIND STUDENT......: use option 's' or 'student'                                    ##"); 
          print("\n##  [option] 'id' [student id] or [option] 'name' [student firstname and lastname]        ##"); 
          print("\n############################################################################################"); 
          print("\n##  TO SAVE EDITED DETAILS......................: use 'done' or use 'q' ot ignore changes ##"); 
          print("\n############################################################################################"); 
      } 
      else if (command == "all"){ 
          help("add");help("search");help("routes");help("remove");help("edit");help("arsubject"); 
          help("records");help("showrecords");help("manage");help("settings"); 
      } 
      else if (command == "q"){ 
          //pass to end help 
      } 
      else{ 
          printer("invh"); 
          help(""); 
      } 
  } 
  
 
  float getGpaScore(string grade){ 
      if (grade == "A"){ 
          return 4.0; 
      }       else if (grade == "B+"){ 
          return 3.5; 
      } 
      else if (grade == "B"){ 
          return 3.0; 
      } 
      else if (grade == "C+"){ 
          return 2.5; 
      } 
      else if (grade == "C"){ 
          return 2.0; 
      } 
      else if (grade == "D+"){ 
          return 1.5; 
      } 
      else if (grade == "D"){ 
          return 1.0; 
      } 
      else if (grade == "E"){ 
          return 0.5; 
      } 
      else if (grade == "F"){ 
          return 0.0; 
      } 
      return -1; 
  } 
  
 
  string GpaCalc(student obj, string type){ 
      float gpa = 0.0;int tch=0;bool empty_score = false; 
      if (type == "sem"){ 
          int len = obj.getSemRecords().size(); 
          vector<record> temp_record = obj.getSemRecords(); 
          for (int i=0;i<len;i++){ 
              if (temp_record[i].mark == -1){ 
                 empty_score = true; 
                  return "**N/A**";                   break; 
              } 
              else{ 
                  tch += temp_record[i].credit_hr; 
                  gpa += getGpaScore(temp_record[i].grade)*temp_record[i].credit_hr; 
              } 
          } 
          if (empty_score == false){ 
              if (len != 0){ 
                  stringstream ss; 
                  ss << gpa/tch; 
                  return ss.str(); 
              } 
              else{ 
                  return "**N/A**"; 
              } 
          } 
      } 
      else if (type == "full"){ 
          int len = obj.getAcaRecords().size(); 
          vector<record> temp_record = obj.getAcaRecords(); 
          for (int i=0;i<len;i++){ 
              if (temp_record[i].mark == -1){ 
                  empty_score = true; 
                  return "**N/A**"; 
                  break; 
              } 
              else{ 
                  tch += temp_record[i].credit_hr; 
                  gpa += getGpaScore(temp_record[i].grade)*temp_record[i].credit_hr; 
              } 
          }           if (empty_score == false){ 
              if (len != 0){ 
                  stringstream ss; 
                 ss << gpa/tch; 
                  return ss.str(); 
              } 
              else{ 
			                    return "**N/A**"; 
              } 
          } 
      } 
  } 
  
 
  
 
  string choice(){ 
      cin.clear(); 
      string v = lower(inputStr("")); 
      if (v=="y"){ 
          return "y"; 
      } 
      else if (v=="n"){ 
          return "n"; 
      } 
      else{ 
          printer("y/n"); 
      } 
      return lower(choice()); 
  } 
  
 
  void exit(){ 
      printer("exit"); 
      string ans = choice(); 
      if (ans == "y"){ 
          //pass to exit 
      } 
      else{ 
          engine(); 
      } 
  } 
  
   
 
  void _add(){ 
     cin.clear(); 
      print("\n\nAdd >> "); 
      string command = lower(inputStr("")); 
      if (command == "s" || command == "student"){ 
          //adding new student 
          bool next = true; 
          while(next != false){ 
              int i = Students.size(); 
              printer("careful"); 
              student studentobj; 
              studentobj.setIndex(i); 
              studentobj.setID(stu_ID+i); 
              print("\nAssigned student ID Number is  :\t");print(studentobj.getID());print("\n"); 
              string firstname = inputStr("\nEnter students firstname Name  :\t"); 
              string lastname = inputStr("\nEnter students lastname Name   :\t"); 
              string othername = inputStr("\nEnter students othername Name  :\t"); 
              string fullname = lastname + " " + firstname + " " + othername;studentobj.setName(fullname); 
              studentobj.setAge(inputInt("\nEnter students age             :\t")); 
              while (studentobj.getAge() < 9 || studentobj.getAge() > 150){ 
                  studentobj.setAge(inputInt("( invalid ) please enter a valid age : ")); 
              } 
              studentobj.setLevel(inputInt("\nEnter students Level           :\t")); 
              int level = studentobj.getLevel(); 
              while(level != 100 && level != 200 && level != 300 && level != 400){ 
                  studentobj.setLevel(inputInt("\nEnter students Level '100','200','300','400' : ")); 
                  level = studentobj.getLevel(); 
              } 
              printer("chol");listItems(DEP_CODES);print("\n"); 
              string code = inputStr("\nEnter Students Department      :\t"); 
              while (findStr(DEP_CODES, code) != true){ 
                  printer("chol");listItems(DEP_CODES);print("\n"); 
                  code = inputStr("\nEnter Students Department  (please select code from the list above)  :\t"); 
              } 
              studentobj.setDepartment(upper(code)); 
              cin.ignore();studentobj.setCourse(getStr("\nEnter Students Course          :\t")); 
              studentobj.setSchfees(inputFloat("\nEnter Students School Fees     :\t")); 
              //pushing student into Students vector lists 
              studentobj.setStatus("active");Students.push_back(studentobj); 
  
 
              printer("addmore"); 
              string ans = choice(); 
              if (ans == "y"){ 
                  continue; 
              } 
              else{ 
                  next = false; 
              } 
          } 
      } 
      else if (command == "l" || command == "staff"){ 
          bool next = true; 
          while(next != false){ 
              int i = Staffs.size(); 
              staff staffobj; 
              printer("careful"); 
              staffobj.setIndex(i); 
              staffobj.setID(sta_ID+i); 
              print("\nAssigned staffs ID Number is : ");print(staffobj.getID());print("\n"); 
              string firstname = inputStr("\nEnter staffs firstname Name  :\t"); 
              string lastname = inputStr("\nEnter staffs lastname Name   :\t"); 
              string othername = inputStr("\nEnter staffs othername Name  :\t"); 
              string b = lastname + " " + firstname + " " + othername;staffobj.setName(b); 
              staffobj.setAge(inputInt("\nEnter staffs age             :\t")); 
              while (staffobj.getAge() < 20 || staffobj.getAge() > 150){ 
                  staffobj.setAge(inputInt("( invalid ) please enter a valid age : ")); 
              } 
              cin.ignore();staffobj.setJob(getStr("\nEnter staffs job             :\t")); 
              printer("chol");listItems(DEP_CODES);print("\n"); 
              string code = inputStr("\nEnter Staffs Department    :\t"); 
              while (findStr(DEP_CODES, code) != true){ 
                  printer("chol");listItems(DEP_CODES);print("\n"); 
                  code = inputStr("\nEnter Staffs Department  (please select code from the list above)  :\t"); 
              } 
              staffobj.setDepartment(upper(code)); 
              //pushing staffobj into Staffs vector list 
              staffobj.setStatus("active");Staffs.push_back(staffobj); 
  
 
              printer("addmore"); 
              string ans = choice(); 
              if (ans == "y"){ 
                  continue; 
              } 
              else{ 
                  next = false; 
              } 
          } 
      } 
      else if (command == "d" || command == "department"){ 
          bool next = true; 
          while(next != false){ 
              printer("careful"); 
              Department depobj; 
              string code = inputStr("\nEnter departments Code Name\t\t:\t"); 
              while (findStr(DEP_CODES, code) == true){ 
                  printer("dchol");listItems(DEP_CODES);print("\n"); 
                  code = inputStr("\nDepartment already exist...Enter another Department Code Name :\t"); 
              } 
              depobj.dep_code = upper(code); 
              cin.ignore();depobj.dep_name = getStr("\nEnter departments Name    \t\t:\t"); 
              int max_years = inputInt("\nEnter the maximum number of years a student in the department is required to study : "); 
              while (max_years < 0 && max_years > 4){ 
                  max_years = inputInt("\nYears must be less than 5    \t\t:\t "); 
              } 
              for (int j=0;j<max_years;j++){ 
                  int level = 100*(j+1); 
                  depobj.dep_courses[j].level = level; 
                  print("\nIn level ");print(level);int subjs = inputInt(", how many courses are available for students : ");print("\n"); 
                  while (subjs < 0 && subjs > 10){ 
                      subjs = inputInt("courses should be less than 10 \t:\t"); 
                  } 
                  cin.ignore(); 
                  for (int k=0;k<subjs;k++){ 
                      cout << "Enter the course code for course  "<< k+1 <<" \t:\t"; 
                      string subj = getStr(""); 
                      while (findStr(depobj.dep_courses[j].subjects,k,subj) == true){ 
                          subj = getStr("( already exist ) enter course code \t:\t"); 
                      } 
                      depobj.dep_courses[j].subjects[k] = subj; 
                  } 
              } 
              //pushing depobj into DEPARTMENTS vector list 
              DEP_CODES.push_back(depobj.dep_code);DEPARTMENTS.push_back(depobj); 
  
 
              printer("addmore"); 
              string ans = choice(); 
              if (ans == "y"){ 
                  continue; 
              } 
              else{ 
                  next = false; 
              } 
          } 
      } 
      else if (command == "help" || command == "h"){ 
          help("add"); 
          _add(); 
      } 
      else if (command == "q"){ 
  
 
      } 
      else{ 
          printer("invh"); 
          _add(); 
      } 
  } 
  
 
  void _remove(student obj){ 
      if (obj.getStatus() != "null"){ 
          printer("choice"); 
          string ans = choice(); 
          if (ans == "y"){ 
              obj.setStatus("removed"); 
              Students[obj.getIndex()] = obj; 
          } 
      } 
  } 
  
 
  void _remove(staff obj){ 
      if (obj.getStatus() != "null"){ 
          printer("choice"); 
          string ans = choice(); 
          if (ans == "y"){ 
		                obj.setStatus("removed"); 
              Staffs[obj.getIndex()] = obj; 
          } 
      } 
  } 
  
 
  void _remove(Department obj){ 
      if (obj.dep_code != "null"){ 
          int len = DEP_CODES.size(); 
          printer("choice"); 
          string ans = choice(); 
          if (ans == "y"){ 
              for (int i=0;i<len;i++){ 
                  if (DEP_CODES[i] == obj.dep_code){ 
                      DEP_CODES.erase(DEP_CODES.begin()+i); 
                      DEPARTMENTS.erase(DEPARTMENTS.begin()+i); 
                     printer("success"); 
                      break; 
                  } 
              } 
          } 
      } 
  } 
  
 
  
 
  void _list(){ 
      cin.clear(); 
      print("\n\nList >> "); 
      string command = lower(inputStr("")); 
      if (command == "s" || command == "student"){ 
          string by = inputStr("\nList by > "); 
          if (by == "all" || by == "a"){ 
              int len = Students.size(); 
              for (int i=0;i<len;i++){ 
                  Students[i].getInfo(); 
              } 
              _list(); 
          } 
          else if (by == "level" || by == "l"){ 
              int level = inputInt("\nWhat level : "); 
              while (level != 100 && level != 200 && level != 300 && level != 400){ 
                 level = inputInt("\nLevel (100, 200, 300, 400) : "); 
              } 
              int len = Students.size(); 
              for (int i=0;i<len;i++){ 
                  if (Students[i].getLevel() == level){ 
                      Students[i].getInfo(); 
                  } 
              } 
              _list(); 
          } 
          else if (by == "residence" || by == "r"){ 
              cin.ignore();string residence = getStr("\nresidence name : "); 
              int len = Students.size(); 
              for (int i=0;i<len;i++){ 
                  if ((lower(Students[i].getResidence()).find(lower(residence))) != string::npos){ 
                      Students[i].getInfo(); 
                  } 
              } 
              _list(); 
         } 
          else if (by == "dep" || by == "d"){ 
              printer("chol");listItems(DEP_CODES);print("\n"); 
              cin.ignore();string dep = getStr("\nWhat department : "); 
              while (findStr(DEP_CODES, dep) != true && dep != "q"){ 
                  printer("chol");listItems(DEP_CODES);print("\n"); 
                  dep = getStr("\nDepartment "+dep+" does not EXIST (enter another or use 'q' to leave) : "); 
              } 
              if (dep == "q"){ 
  
 
              } 
              else{ 
                  int len = DEPARTMENTS.size(); 
                  for (int i=0;i<len;i++){ 
                      if (DEPARTMENTS[i].dep_code == upper(dep)){ 
                          dep = DEPARTMENTS[i].dep_name; 
                          break; 
                      } 
                  } 
                  len = Students.size(); 
                  for (int i=0;i<len;i++){ 
                      if (Students[i].getDepartment() == dep){ 
                          Students[i].getInfo(); 
                      } 
                  } 
                  _list(); 
              } 
          } 
          else if (command == "help" || command == "h"){ 
             help("list"); 
             _list(); 
          } 
          else if (command == "q"){ 
              //pass to end help 
          } 
          else{ 
              printer("invh"); 
              _list(); 
          } 
      } 
      else if (command == "l" || command == "staff"){ 
          string by = inputStr("\nList by > "); 
          if (by == "all" || by == "a"){ 
              int len = Staffs.size(); 
              for (int i=0;i<len;i++){ 
                  Staffs[i].getInfo(); 
              } 
              _list(); 
          } 
          else if (by == "dep" || by == "d"){ 
              printer("chol");listItems(DEP_CODES);print("\n"); 
              cin.ignore();string dep = getStr("\nWhat department : "); 
              while (findStr(DEP_CODES, dep) != true && dep != "q"){ 
                  printer("chol");listItems(DEP_CODES);print("\n"); 
                  dep = getStr("Department "+dep+" does not EXIST (enter another or use 'q' to leave) : "); 
              } 
              if (dep == "q"){ 
  
               } 
              else{ 
                  int len = DEPARTMENTS.size(); 
                  for (int i=0;i<len;i++){ 
                      if (DEPARTMENTS[i].dep_code == upper(dep)){ 
                          dep = DEPARTMENTS[i].dep_name; 
                          break; 
                      } 
                  } 
                  len = Staffs.size(); 
                  for (int i=0;i<len;i++){ 
                      if (Staffs[i].getDepartment() == dep){ 
                          Staffs[i].getInfo(); 
                      } 
                  } 
                  _list(); 
              } 
          } 
          else if (command == "help" || command == "h"){ 
             help("list"); 
             _list(); 
          } 
          else if (command == "q"){ 
              //pass to end help 
          } 
          else{ 
              printer("invh"); 
              _list(); 
          } 
      } 
      else if (command == "d" || command == "department"){ 
         int len = DEPARTMENTS.size(); 
         for (int i=0;i<len;i++){ 
              print("\n\nDepartment Code :\t");print(DEPARTMENTS[i].dep_code); 
              print("\nDepartment Name :\t");print(DEPARTMENTS[i].dep_name); 
         } 
         _list(); 
      } 
      else if (command == "help" || command == "h"){ 
         help("list"); 
         _list(); 
      } 
      else if (command == "q"){ 
          //pass to end help 
      } 
      else{ 
          printer("invh"); 
          _list(); 
      } 
  } 
  
 
  student searchStudent(int val){ 
      int index =  val - stu_ID; 
      int len = Students.size(); 
      if (index >= len || index < 0){ 
          printer("cantfind"); 
      }else{ 
          printer("found"); 
          return Students[index]; 
      } 
      student _empty; 
      return _empty; 
  } 
  
 
  staff searchStaff(int val){ 
      int index = val - sta_ID; 
      int len = Staffs.size(); 
      if (index >= len || index < 0){ 
          printer("cantfind"); 
      }else{ 
          printer("found"); 
          return Staffs[index]; 
      } 
      staff _empty; 
      return _empty; 
  } 
  
 
  student searchStudent(string val){ 
      int len = Students.size(); 
      size_t found; 
      for (int i=0;i<len;i++){ 
          if (isSpace(val) == false && val.length()>5){ 
              found = lower(Students[i].getName()).find(lower(val)); 
              if (found != string::npos){ 
                  printer("found"); 
                  return Students[i]; 
              } 
          } 
          else{ 
              break; 
          } 
      } 
      printer("cantfind"); 
      student _empty; 
      return _empty; 
  } 
  
 
  staff searchStaff(string val){ 
      int len = Staffs.size(); 
	        size_t found; 
      for (int i=0;i<len;i++){ 
          if (isSpace(val) == false && val.length()>5){ 
              found = lower(Staffs[i].getName()).find(lower(val)); 
              if (found != string::npos){ 
                  printer("found"); 
                  return Staffs[i]; 
              } 
         } 
          else{ 
		                break; 
          } 
      } 
      printer("cantfind"); 
      staff _empty; 
      return _empty; 
  } 
  
 
  void addremoveSubject(student obj){ 
      string command = lower(inputStr("\n\nAdd\\Remove Course : ")); 
      vector<string> list = obj.getRegCourses(); 
      if (command == "add" || command == "a"){ 
          string ans = inputStr("Is it a main or free course? (main/free) : "); 
          if (ans == "main" || ans == "m"){ 
              printer("chol");obj.listRegCourses();print("\n"); 
              cin.ignore();string subj = getStr("\nEnter the subject :\t"); 
              while (findStr(list, subj) != true || findStr(obj.getSubjects(), subj) == true){ 
                  printer("chol");obj.listRegCourses();print("\n"); 
                  subj = getStr("\n(invalid choice) Enter the subject :\t"); 
              } 
              obj.setSubject(upper(subj)); 
          } 
          else if (ans == "free" || ans == "f"){ 
              cin.ignore();string subj = getStr("\nEnter the subject :\t"); 
              while (findStr(list, subj) == true){ 
                  printer("chol");obj.getRegCourses();print("\n"); 
                  subj = getStr("\n(not a free elective) Enter a different subject :\t"); 
              } 
              obj.setSubject("FE-" + upper(subj)); 
          } 
          else{ 
              help("arsubject"); 
          } 
          addremoveSubject(obj); 
      } 
      else if (command == "remove" || command == "r"){ 
          printer("chol");obj.listSubjects();print("\n"); 
          cin.ignore();string subj = getStr("\nselect subject from list to remove : "); 
          while (findStr(list, subj) != true){ 
              printer("chol");obj.listSubjects();print("\n"); 
              subj = getStr("\nplease select subject from list to remove : "); 
          } 
          obj.removeSubject(upper(subj)); 
          addremoveSubject(obj); 
      } 
      else if(command == "help" || command == "h"){ 
          help("arsubject"); 
          addremoveSubject(obj); 
      } 
      else if(command == "done"){ 
          //commit changes to global Students 
          printer("saved"); 
          Students[obj.getIndex()] = obj; 
          //pass to search 
     } 
      else if(command == "q"){ 
          printer("ignored"); 
          //pass to exit 
      } 
      else{ 
          printer("invcm"); 
          addremoveSubject(obj); 
      } 
  } 
  
 
  
 
  void addremoveSubject(staff obj){ 
      string command = lower(inputStr("\n\nAdd\\Remove Course : ")); 
      vector<string> list = obj.getRegCourses(); 
      if (command == "add" || command == "a"){ 
              printer("chol");obj.listRegCourses();print("\n"); 
              cin.ignore();string subj = getStr("\nEnter the subject :\t"); 
              while (findStr(list, subj) != true || findStr(obj.getSubjects(), subj) == true){ 
                  printer("chol");obj.listRegCourses();print("\n"); 
                  subj = getStr("\n(invalid choice) Enter the subject :\t"); 
              } 
              obj.setSubject(upper(subj)); 
              addremoveSubject(obj); 
      }else if (command == "remove" || command == "r"){           printer("chol");obj.listSubjects();print("\n"); 
          cin.ignore();string subj = getStr("\nselect subject from list to remove : "); 
          while (findStr(list, subj) != true){ 
              printer("chol");obj.listSubjects();print("\n"); 
              subj = getStr("\nplease select subject from list to remove : "); 
          } 
          obj.removeSubject(upper(subj)); 
          addremoveSubject(obj); 
      } 
      else if(command == "help" || command == "h"){ 
          help("arsubject"); 
          addremoveSubject(obj); 
      } 
      else if(command == "done"){ 
          //commit changes to global Students 
          Staffs[obj.getIndex()] = obj; 
          //pass to search 
      } 
      else if(command == "q"){ 
          //pass to exit 
      } 
      else{ 
          printer("invcm"); 
          addremoveSubject(obj); 
      } 
  } 
  
 
  
 
  void _edit(student obj){ 
      if (obj.getStatus() != "null"){ 
         string edit = lower(inputStr("\n\nEdit Student's > ")); 
          if (edit == "name"){ 
              print("\nStudents name : ");print(obj.getName()); 
              cin.ignore();obj.setName(getStr("\n\nChange to : ")); 
              _edit(obj); 
          } 
          else if (edit == "age"){ 
              print("\nStudents age : ");print(obj.getAge()); 
              obj.setAge(inputInt("\n\nChange to : ")); 
              while (obj.getAge() < 9 || obj.getAge() > 150){ 
                  obj.setAge(inputInt("( invalid ) please enter a valid age : ")); 
              } 
              _edit(obj); 
          } 
          else if (edit == "level"){ 
              print("\nStudents level : ");print(obj.getLevel()); 
              int level = inputInt("\n\nChange to : "); 
              while (level != 100 && level != 200 && level != 300 && level != 400){ 
                 level = inputInt("\nChange to 100,200,300 or 400: "); 
              } 
              print("\nStudents subjects will reset... Student will Have To Register Subjects Again !!!\n"); 
              printer("choice"); 
              string ans = choice(); 
              if (ans == "y"){ 
                  obj.setLevel(level); 
                  obj.refresh(); 
              } 
              _edit(obj); 
          } 
          else if (edit == "course"){ 
              print("\nStudents course : ");print(obj.getCourse()); 
              cin.ignore();obj.setCourse(getStr("\n\nChange to : ")); 
              _edit(obj); 
          } 
          else if (edit == "dep" || edit == "department"){ 
              print("\nStudents Department : ");print(obj.getDepartment()); 
              printer("chol");listItems(DEP_CODES);print("\n"); 
              string code = inputStr("\n\nChange to : "); 
              while (findStr(DEP_CODES, code) != true){ 
                  code = inputStr("\n\n(select code from list above) Change to : "); 
              } 
              obj.setDepartment(code); 
              _edit(obj); 
          } 
          else if (edit == "subjects" || edit == "subj"){ 
              if (helptips == 1){ 
                  help("arsubject"); 
              } 
              print("\n\n\nStudents subject : \n");obj.listSubjects();print("\n"); 
              addremoveSubject(obj); 
              obj = Students[obj.getIndex()]; 
              _edit(obj); 
          } 
          else if (edit == "residence"){ 
              print("\nStudents Residence : ");print(obj.getResidence()); 
              cin.ignore();obj.setResidence(getStr("\n\nChange to : ")); 
              _edit(obj); 
          } 
          else if (edit == "help" || edit == "h"){ 
              help("editstudent"); 
              _edit(obj); 
          } 
          else if (edit == "done"){ 
              //commit changes and push 
              Students[obj.getIndex()] = obj; 
              printer("saved"); 
              //pass to search 
          } 
          else if (edit == "q"){ 
              //forget changes and quit route 
              printer("ignored"); 
              //pass to exit 
          } 
          else{ 
              printer("invcm"); 
              _edit(obj); 
          } 
      } 
  } 
  
 
  
 
  void _edit(staff obj){ 
      //check if object is NULL  
	       string edit = lower(inputStr("\n\nEdit Staff's > ")); 
      if (edit == "name"){ 
          print("\nStaffs name : ");print(obj.getName()); 
          cin.ignore();obj.setName(getStr("\n\nChange to : ")); 
          _edit(obj); 
      } 
      else if (edit == "job"){ 
          print("\nStaffs job : ");print(obj.getJob()); 
          cin.ignore();obj.setJob(getStr("\n\nChange to : ")); 
          _edit(obj); 
      }else if (edit == "age"){ 
          print("\nStaffs age : ");print(obj.getAge()); 
          obj.setAge(inputInt("\n\nChange to : ")); 
          while (obj.getAge() < 20 || obj.getAge() > 150){ 
              obj.setAge(inputInt("( invalid ) please enter a valid age : ")); 
          } 
          _edit(obj); 
      } 
      else if (edit == "dep" || edit == "department"){ 
          print("\nStaffs Department : ");print(obj.getDepartment()); 
          printer("chol");listItems(DEP_CODES);print("\n"); 
          string code = inputStr("\n\nChange to : "); 
          while (findStr(DEP_CODES, code) != true){ 
              code = inputStr("\n\n(select code from list above) Change to : "); 
          } 
          obj.setDepartment(code); 
          _edit(obj); 
      } 
      else if (edit == "subjects" || edit == "subj"){ 
          print("\n\n\nStaffs subject Teaching : \n");obj.listSubjects();print("\n"); 
         addremoveSubject(obj); 
      } 
      else if (edit == "residence"){ 
          print("\nStaffs Residence : ");print(obj.getResidence()); 
          cin.ignore();obj.setResidence(getStr("\n\nChange to : ")); 
          _edit(obj); 
      } 
      else if (edit == "job"){ 
          print("\nStaffs Job : ");print(obj.getJob()); 
          cin.ignore();obj.setJob(getStr("\n\nChange to : ")); 
          _edit(obj); 
      } 
      else if (edit == "help" || edit == "h"){ 
          help("editstaff"); 
          _edit(obj); 
      } 
      else if (edit == "done"){ 
          //commit changes and push 
          Staffs[obj.getIndex()] = obj; 
          printer("saved"); 
          //pass to exit 
      } 
      else if (edit == "q"){ 
          //forget changes and quit route 
          printer("ignored"); 
      } 
      else{ 
          printer("invcm"); 
          _edit(obj); 
      } 
  } 
  
 
  
 
  
 
  void _edit(Department obj){ 
      //check if object is NULL 
      if (obj.dep_code != "null"){ 
          int len = DEP_CODES.size(); 
          int index; 
          for (int i=0;i<len;i++){ 
              if (DEP_CODES[i] == obj.dep_code){ 
                  index = i; 
                  break; 
              } 
          } 
          string edit = lower(inputStr("\n\nEdit Department's > ")); 
          if (edit == "code"){ 
              print("\nDepartment Code : ");print(obj.dep_code); 
              cin.ignore();obj.dep_code = upper(getStr("\nChange to :\t")); 
              _edit(obj); 
          } 
          else if (edit == "name"){ 
              print("\nDepartment Name : ");print(obj.dep_name); 
              cin.ignore();obj.dep_name = upper(getStr("\nChange to :\t")); 
              _edit(obj); 
          } 
          else if (edit == "courses"){ 
              //print level and its courses 
              for (int i=0;i<4;i++){ 
                 print("\n\nOld Courses for level ");print(obj.dep_courses[i].level);print("\n"); 
                  for (int j=0;j<10;j++){ 
                      try{ 
                          print(obj.dep_courses[i].subjects[j]); 
                          if ((j+1)%3 == 0){ 
                              print("\n"); 
                          }else{ 
                              print("\t\t"); 
                          } 
                      } 
                      catch(...){ 
                          break; 
                      } 
                  } 
              } 
  
 
              int max_years = inputInt("\n\nEnter the maximum number of years a student in the department is required to study : "); 
              for (int j=0;j<max_years;j++){ 
                  int level = 100*(j+1); 
                  obj.dep_courses[j].level = level; 
                  print("\nIn level ");print(level);int subjs = inputInt(", how many courses are available for students : ");print("\n"); 
                  while (subjs > 10){ 
                      subjs = inputInt("courses should be less than 10 : "); 
                  } 
                  for (int k=0;k<subjs;k++){ 
                      cout << "Enter the course code for course "<< k+1 <<" : "; 
                      cin.ignore();obj.dep_courses[j].subjects[k] = getStr(""); 
                  } 
              } 
  
 
              _edit(obj); 
          } 
          else if (edit == "done"){ 
              //commit changes and push 
              DEPARTMENTS[index] = obj; 
              DEP_CODES[index] = obj.dep_code; 
              printer("saved"); 
              //pass to exit 
          } 
          else if (edit == "q"){ 
              //forget changes and quit route 
              printer("ignored"); 
          } 
          else if (edit == "help" || edit == "h"){ 
              help("exploredep"); 
              _edit(obj); 
          } 
          else{ 
              printer("invcm"); 
              _edit(obj); 
          } 
      } 
  } 
  
 
  
 
  void explore(student obj, string status){ 
      //check if object is NULL 
      if (obj.getStatus() != "null"){ 
          obj = Students[obj.getIndex()]; 
          if (status == "new"){ 
              printer("explore"); 
          } 
          string get = lower(inputStr("\n\nGet Student's > ")); 
          if (get == "id"){ 
              print("\n");print(obj.getID()); 
              explore(obj, "pass"); 
          } 
          else if (get == "name"){ 
              print("\n");print(obj.getName()); 
              explore(obj, "pass"); 
          } 
          else if (get == "age"){ 
              print("\n");print(obj.getAge());print(" years."); 
              explore(obj, "pass"); 
          } 
          else if (get == "level"){ 
              print("\n");print(obj.getLevel()); 
              explore(obj, "pass"); 
          } 
        else if (get == "status"){ 
		              print("\n");print(obj.getStatus()); 
              explore(obj, "pass"); 
          } 
          else if (get == "residence"){ 
              print("\n");print(obj.getResidence()); 
              explore(obj, "pass"); 
          } 
          else if (get == "course"){ 
              print("\n");print(obj.getCourse()); 
              explore(obj, "pass"); 
          } 
          else if (get == "dep" || get == "department"){ 
              print("\n");print(obj.getDepartment()); 
              explore(obj, "pass"); 
          } 
          else if (get == "subjects" || get == "subj"){ 
              print("\n");obj.listSubjects(); 
              explore(obj, "pass"); 
          } 
          else if (get == "reg_subjects" || get == "reg_subj"){ 
              print("\n");obj.listRegCourses(); 
              explore(obj, "pass"); 
          } 
          else if (get == "schoolfees"){ 
              print("\n");print(obj.getSchfees()); 
              explore(obj, "pass"); 
          } 
          else if (get == "info"){ 
              obj.getInfo(); 
              explore(obj, "pass"); 
          } 
          else if (get == "help" || get == "h"){ 
              help("explorestudent"); 
              explore(obj, "pass"); 
          } 
          else if (get == "q"){ 
              //pass 
          } 
          else{ 
              printer("invcm"); 
              explore(obj, "pass"); 
          } 
      } 
  } 
  
 
  
 
  void explore(staff obj, string status){ 
      //check if object is NULL 
      if (obj.getStatus() != "null"){ 
          obj = Staffs[obj.getIndex()]; 
          if (status == "new"){ 
              printer("explore"); 
          } 
          string get = lower(inputStr("\n\nGet Staff's > ")); 
          if (get == "id"){ 
              print("\n");print(obj.getID()); 
              explore(obj, "pass"); 
          } 
          else if (get == "name"){ 
              print("\n");print(obj.getName()); 
              explore(obj, "pass"); 
          } 
          else if (get == "age"){ 
              print("\n");print(obj.getAge());print(" years."); 
              explore(obj, "pass"); 
          } 
          else if (get == "status"){ 
              print("\n");print(obj.getStatus()); 
              explore(obj, "pass"); 
          } 
          else if (get == "job"){ 
              print("\n");print(obj.getJob()); 
              explore(obj, "pass"); 
          } 
          else if (get == "residence"){ 
              print("\n");print(obj.getResidence()); 
              explore(obj, "pass"); 
          } 
          else if (get == "dep" || get == "department"){ 
              print("\n");print(obj.getDepartment()); 
              explore(obj, "pass"); 
          } 
          else if (get == "subjects" || get == "subj"){ 
              print("\n");obj.listSubjects(); 
              explore(obj, "pass"); 
          } 
          else if (get == "info"){ 
              obj.getInfo(); 
              explore(obj, "pass"); 
          } 
          else if (get == "help" || get == "h"){ 
              help("explorestaff"); 
              explore(obj, "pass"); 
          } 
         else if (get == "q"){ 
              //pass 
          } 
          else{ 
              printer("invcm"); 
              explore(obj, "pass"); 
          } 
      } 
  } 
  
 
  Department searchDepartments(string val){ 
      int len = DEP_CODES.size(); 
      for (int i=0;i<len;i++){ 
          if (isSpace(val) == false && val.length()>5){ 
              if (val == DEP_CODES[i]){ 
                  return DEPARTMENTS[i]; 
                  break; 
              } 
              else if (i == len-1){ 
                  printer("cantfind"); 
              } 
          } 
          else{ 
              break; 
          } 
      } 
      Department _empty;_empty.dep_code = "null"; 
      return _empty; 
  } 
 
  void explore(Department obj, string status){ 
      //check if object is NULL 
      if (obj.dep_code != "null"){ 
          //Department obj = DEPARTMENTS[obj.getIndex()]; 
          if (status == "new"){ 
              printer("explore"); 
          } 
          string get = lower(inputStr("\n\nGet Department's > ")); 
          if (get == "code"){ 
              print("\n");print(obj.dep_code); 
              explore(obj, "pass"); 
          } 
          else if (get == "name"){ 
              print("\n");print(obj.dep_name); 
              explore(obj, "pass"); 
          } 
          else if (get == "courses"){ 
              //print level and its courses 
              for (int i=0;i<4;i++){ 
                  print("\n\nCourses for level ");print(obj.dep_courses[i].level);print("\n"); 
                  for (int j=0;j<10;j++){ 
                      try{ 
                          print(obj.dep_courses[i].subjects[j]); 
                          if ((j+1)%3 == 0){ 
                              print("\n"); 
                          }else{ 
                              print("\t\t"); 
                          } 
                      } 
                      catch(...){ 
                          break; 
                      } 
                  } 
              } 
              explore(obj, "pass"); 
          } 
          else if (get == "edit"){ 
              _edit(obj); 
          } 
          else if (get == "remove"){ 
              _remove(obj); 
          } 
          else if (get == "q"){ 
              //pass to quit 
          } 
          else if (get == "help" || get == "h"){ 
              help("exploredep");               
			  explore(obj, "pass"); 
          } 
          else{ 
              printer("invcm"); 
              explore(obj, "pass"); 
          } 
      } 
  } 
  
 
  
 
  void entryRecords(student obj){ 
      obj = Students[obj.getIndex()]; 
      int len = obj.getSubjects().size(); 
      print("Record Entry for Year ");print(year);print(" Semester ");print(semester); 
      for (int i=0;i<len;i++){ 
          if (obj.getSemRecords()[i].mark == -1){ 
              print("\n\nSubject :\t");print(obj.getSemRecords()[i].course_name); 
              print("\nDo you want to record marks for this subject : "); 
              string ans = choice(); 
              if (ans == "y"){ 
			                    int credit_h = inputInt("Credit Hour(s)\t:\t"); 
                  while (0 > credit_h || credit_h > 3){ 
                      credit_h = inputInt("(invalid) Credit Hour(s)\t:\t"); 
                  } 
                  int score = inputInt("Enter Mark\t:\t"); 
                  while (0 > score || score >100){ 
                      score = inputInt("(invalid) Enter Mark\t:\t"); 
                  } 
                  obj.recordMark(i, credit_h, score); 
              } 
          } 
      } 
      Students[obj.getIndex()] = obj; 
  } 
  
 
  void editRecords(student obj){ 
      obj = Students[obj.getIndex()]; 
      int len = obj.getSubjects().size(); 
      print("Record Entry for Year ");print(year);print(" Semester ");print(semester); 
      for (int i=0;i<len;i++){ 
          if (obj.getSemRecords()[i].mark != -1){ 
              print("\n\nSubject :\t");print(obj.getSemRecords()[i].course_name); 
              print("\nDo you want to edit marks for this subject : "); 
              string ans = choice(); 
              if (ans == "y"){ 
                  int credit_h = inputInt("Credit Hour(s)\t:\t"); 
                  while (0 > credit_h || credit_h > 3){ 
                      credit_h = inputInt("(invalid) Credit Hour(s)\t:\t"); 
                  } 
                  int score = inputInt("Enter Mark\t:\t"); 
                  while (0 > score || score >100){ 
                      score = inputInt("(invalid) Enter Mark\t:\t"); 
                  } 
                  obj.recordMark(i, credit_h, score); 
              } 
          } 
      } 
      Students[obj.getIndex()] = obj; 
  } 
  
 
  
 
  void exportRecords(student obj, string opt){ 
      //display academic records 
      if (obj.getStatus() != "null"){ 
          ofstream writer; 
          stringstream ss; 
          ss << obj.getID(); 
          if (opt == "full"){ 
              string filename = ss.str() + "_full_records.txt"; 
              writer.open(filename.c_str()); 
              int len = obj.getAcaRecords().size(); 
              writer << "\n\n8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8="; 
              writer << "\n********************************************************************************************"; 
              writer << "\nName : " << obj.getName() << "\t\tDepartment : " << obj.getDepartment(); 
              writer << "\nCourse : " << obj.getCourse() << "\tSemester : " << semester; 
              writer << "\tLevel : " << obj.getLevel() << "\t\tGPA :\t" << GpaCalc(obj,"full"); 
              writer << "\n********************************************************************************************"; 
              writer << "\n============================================================================================"; 
              int sem = obj.getAcaRecords()[0].semester;bool checker; 
              for (int i=0;i<len;i++){ 
                  checker = (obj.getAcaRecords()[i].semester == sem); 
                  if (checker == false){ 
                      sem = obj.getAcaRecords()[i].semester; 
                      writer << "\n\n--------------------------------------------------------------------------------------------"; 
                  } 
                  if (obj.getAcaRecords()[i].mark != -1){ 
                      writer << "\n\nSubject :\t" << obj.getAcaRecords()[i].course_name; 
                      writer << "\t\tMark :\t" << obj.getAcaRecords()[i].mark; 
                      writer << "\t\tGrade :\t" << obj.getAcaRecords()[i].grade; 
                  } 
                  else{ 
                      writer << "\n\nSubject :\t" << obj.getAcaRecords()[i].course_name; 
                      writer << "\t\tMark :\t" << "**N/A**"; 
                      writer << "\t\tGrade :\t" << "**N/A**"; 
                  } 
              } 
              writer << "\n\n============================================================================================"; 
              writer << "\n8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8="; 
              writer.close(); 
              printer("success"); 
          } 
          else if (opt == "sem"){ 
              string filename = ss.str() + "_sem_records.txt"; 
              writer.open(filename.c_str()); 
              int len = obj.getSubjects().size(); 
              writer << "\n\n8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8="; 
              writer << "\n********************************************************************************************"; 
              writer << "\nName : " << obj.getName() << "\tCourse : " << obj.getCourse() << "\tLevel : " << obj.getLevel(); 
              writer << "\nRecords for Year " << year << "\\" << year+1 << "\t\tSemester " << semester << "\t\tGPA :\t" << GpaCalc(obj,"sem"); 
              writer << "\n********************************************************************************************"; 
              writer << "\n============================================================================================"; 
              for (int i=0;i<len;i++){ 
                  if (obj.getSemRecords()[i].mark != -1){ 
                      writer << "\n\nSubject :\t" << obj.getSemRecords()[i].course_name; 
                      writer << "\t\tMark :\t" << obj.getSemRecords()[i].mark; 
                      writer << "\t\tGrade :\t" << obj.getSemRecords()[i].grade;                   } 
                  else{ 
                      writer << "\n\nSubject :\t" << obj.getSemRecords()[i].course_name; 
                      writer << "\t\tMark :\t" << "**N/A**"; 
                      writer << "\t\tGrade :\t" << "**N/A**"; 
                  } 
              } 
              writer << "\n\n============================================================================================"; 
              writer << "\n8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8="; 
              writer.close(); 
              printer("success"); 
          } 
      } 
  } 
  
 
  
 
  
 
  void showRecords(student obj){ 
      //display academic records 
      if (obj.getStatus() != "null"){ 
          obj = Students[obj.getIndex()]; 
          cin.clear(); 
          print("\n\n\nShow Records (f/s) >> "); 
          string command = lower(inputStr("")); 
          if (command == "full" || command == "f"){ 
              int len = obj.getAcaRecords().size(); 
              print("\n\n8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8="); 
              print("\n********************************************************************************************"); 
              print("\nName : ");print(obj.getName());print("\t\tDepartment : ");print(obj.getDepartment()); 
              print("\nCourse : ");print(obj.getCourse());print("\tSemester : ");print(semester); 
              print("\tLevel : ");print(obj.getLevel());print("\t\tGPA :\t");print(GpaCalc(obj,"full")); 
              print("\n********************************************************************************************"); 
              print("\n============================================================================================"); 
              int sem = obj.getAcaRecords()[0].semester;bool checker; 
              for (int i=0;i<len;i++){ 
                  checker = (obj.getAcaRecords()[i].semester == sem); 
                  if (checker == false){ 
                      sem = obj.getAcaRecords()[i].semester; 
                      print("\n\n--------------------------------------------------------------------------------------------d"); 
                  } 
                  if (obj.getAcaRecords()[i].mark != -1){ 
                      print("\n\nSubject :\t");print(obj.getAcaRecords()[i].course_name); 
                      print("\t\tMark :\t");print(obj.getAcaRecords()[i].mark); 
                      print("\t\tGrade :\t");print(obj.getAcaRecords()[i].grade); 
                  } 
                  else{ 
                      print("\n\nSubject :\t");print(obj.getAcaRecords()[i].course_name); 
                      print("\t\tMark :\t");print("**N/A**"); 
                      print("\t\tGrade :\t");print("**N/A**"); 
                  } 
              } 
              print("\n\n============================================================================================"); 
              print("\n8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8="); 
              showRecords(obj); 
          } 
          else if (command == "sem" || command == "s"){ 
              int len = obj.getSubjects().size(); 
              print("\n\n8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8="); 
              print("\n********************************************************************************************"); 
              print("\nName : ");print(obj.getName());print("\tCourse : ");print(obj.getCourse());print("\tLevel : ");print(obj.getLevel()); 
              print("\nRecords for Year ");print(year);print("\\");print(year+1);print("\t\tSemester ");print(semester);print("\t\tGPA :\t");print(GpaCalc(obj,"sem")); 
              print("\n********************************************************************************************"); 
              print("\n============================================================================================"); 
              for (int i=0;i<len;i++){ 
                  if (obj.getSemRecords()[i].mark != -1){ 
                      print("\n\nSubject :\t");print(obj.getSemRecords()[i].course_name); 
                      print("\t\tMark :\t");print(obj.getSemRecords()[i].mark); 
                      print("\t\tGrade :\t");print(obj.getSemRecords()[i].grade); 
                  } 
                  else{ 
                      print("\n\nSubject :\t");print(obj.getSemRecords()[i].course_name); 
                      print("\t\tMark :\t");print("**N/A**"); 
                      print("\t\tGrade :\t");print("**N/A**"); 
                  } 
              } 
              print("\n\n============================================================================================"); 
              print("\n8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8=8="); 
              showRecords(obj); 
          } 
          else if (command == "gpa"){ 
              print("\nStudents GPA for the Semester is :\t");GpaCalc(obj, "sem"); 
              print("\nStudents Total GPA is :\t\t");GpaCalc(obj, "full"); 
             showRecords(obj); 
          } 
          else if (command == "exp" || command == "e"){ 
             string opt = lower(inputStr("\nExport Records (f/s) : ")); 
             while (opt != "f" && opt != "s"){ 
                  opt = lower(inputStr("( invalid ) enter full records - 'f' or semester records - 's'   : ")); 
             } 
             if (opt == "f"){ 
                  exportRecords(obj, "full"); 
             } 
             else{ 
                  exportRecords(obj, "sem"); 
             } 
          } 
          else if (command == "help" || command == "h"){ 
             help("showrecords"); 
             showRecords(obj); 
          } 
          else if (command == "q"){ 
              //pass to end help 
          } 
          else{ 
              printer("invh"); 
              showRecords(obj); 
          } 
      } 
  } 
  
 
  
 
  void _records(student obj){ 
      if (obj.getStatus() != "null" && obj.getStatus() != "removed"){ 
          cin.clear(); 
          print("\n\nRecords Goto >> "); 
          string command = lower(inputStr("")); 
          if (command == "entry" || command == "en"){ 
              entryRecords(obj); 
              obj = Students[obj.getIndex()]; 
              _records(obj); 
          } 
          else if (command == "edit" || command == "ed"){ 
              editRecords(obj); 
              obj = Students[obj.getIndex()]; 
              _records(obj); 
          } 
          else if (command == "show" || command == "s"){ 
              if (helptips == 1){ 
                  help("showrecords"); 
              } 
             showRecords(obj); 
             _records(obj); 
          } 
          else if (command == "help" || command == "h"){ 
             help("records"); 
             _records(obj); 
          } 
          else if (command == "done"){ 
              Students[obj.getIndex()] = obj; 
              printer("saved"); 
          } 
          else if (command == "q"){ 
              //pass to end help 
              printer("ignored"); 
          } 
          else{ 
              printer("invh"); 
              _records(obj); 
          } 
      } 
      else if (obj.getStatus() == "removed"){ 
          printer("error"); 
          printer("removed"); 
      } 
	    } 
  
 
  
 
  void _manage(student obj){ 
      if (obj.getStatus() != "null"  && obj.getStatus() != "removed"){ 
          print("\n\nManage Goto >> ");cin.clear(); 
          string command = lower(inputStr("")); 
          if (command == "pay" || command == "p"){ 
              print("\nStudents current fees is : GHC ");print(obj.getSchfees()); 
              obj.paySchfees(inputFloat("\nPay School fees : GHC ")); 
              _manage(obj); 
          } 
          else if (command == "set" || command == "s"){ 
              print("\nStudents current fees is : GHC ");print(obj.getSchfees()); 
              obj.setSchfees(inputFloat("\nSet School fees : GHC ")); 
              _manage(obj); 
          } 
          else if (command == "add" || command == "a"){ 
              print("\nStudents current fees is : GHC ");print(obj.getSchfees()); 
              obj.addSchfees(inputFloat("\nPay School fees : GHC ")); 
              _manage(obj); 
          } 
          else if (command == "remove" || command == ""){ 
                  _remove(obj); 
                  obj = Students[obj.getIndex()]; 
                  if (obj.getStatus() != "removed"){ 
                      _manage(obj); 
                  } 
  
 
          } 
          else if (command == "help" || command == "h"){ 
             help("manage"); 
             _manage(obj); 
          } 
          else if (command == "done"){ 
              Students[obj.getIndex()] = obj; 
              printer("success"); 
          } 
          else if (command == "q"){ 
              printer("ignored"); 
          } 
          else{ 
              printer("invh"); 
              _manage(obj); 
          } 
      }else if (obj.getStatus() == "removed"){ 
          printer("removed");printer("activate"); 
          string ans = choice(); 
          if (ans == "y"){ 
              obj.setStatus("active"); 
              Students[obj.getIndex()] = obj; 
              printer("success"); 
          } 
      } 
  } 
  
 
  void _manage(staff obj){ 
      if (obj.getStatus() != "null"  && obj.getStatus() != "removed"){ 
          print("\n\nManage Goto >> ");cin.clear(); 
          string command = lower(inputStr("")); 
          if (command == "remove" || command == ""){ 
              _remove(obj); 
              obj = Staffs[obj.getIndex()]; 
              if (obj.getStatus() != "removed"){ 
                  _manage(obj); 
              } 
  
 
          } 
          else if (command == "help" || command == "h"){ 
             help("manage"); 
             _manage(obj); 
          } 
          else if (command == "done"){ 
              Staffs[obj.getIndex()] = obj; 
              printer("success"); 
          } 
          else if (command == "q"){ 
              printer("ignored"); 
          } 
          else{ 
              printer("invh"); 
              _manage(obj); 
          } 
      }else if (obj.getStatus() == "removed"){ 
          printer("removed");printer("activate"); 
          string ans = choice(); 
          if (ans == "y"){ 
              obj.setStatus("active"); 
              Staffs[obj.getIndex()] = obj; 
              printer("success"); 
          } 
      } 
  } 
  
 
  
 
  void selectRoute(student obj){ 
      string route = lower(inputStr("\n\nRoute Goto >> ")); 
      if (route == "explore"){ 
          if (helptips == 1){ 
              help("explorestudent"); 
          } 
          explore(obj, "pass"); 
          selectRoute(obj); 
      } 
      else if (route == "edit"){ 
          if (helptips == 1){ 
              help("editstudent"); 
          } 
          _edit(obj); 
          obj = Students[obj.getIndex()]; 
          selectRoute(obj); 
      } 
      else if (route == "records"){ 
          if (helptips == 1){ 
              help("records"); 
          } 
          _records(obj); 
          obj = Students[obj.getIndex()]; 
          selectRoute(obj); 
      } 
      else if (route == "manage"){ 
          if (helptips == 1){ 
              help("manage"); 
          } 
          _manage(obj); 
          obj = Students[obj.getIndex()]; 
          selectRoute(obj); 
      } 
      else if (route == "help" || route == "h"){ 
          help("routes"); 
          selectRoute(obj); 
      } 
      else if (route == "q"){ 
          //pass to search 
      } 
      else{ 
          printer("invcm"); 
          selectRoute(obj); 
      } 
  } 
  
 
  void selectRoute(staff obj){ 
      string route = lower(inputStr("\n\nRoute Goto >> ")); 
      if (route == "explore"){ 
          if (helptips == 1){ 
              help("explorestaff"); 
          } 
          explore(obj, "pass"); 
          selectRoute(obj); 
      } 
      else if (route == "edit"){ 
          if (helptips == 1){ 
              help("editstaff");           } 
          _edit(obj); 
          obj = Staffs[obj.getIndex()]; 
          selectRoute(obj); 
      } 
      else if (route == "manage"){ 
          if (helptips == 1){ 
              help("manage"); 
          } 
          _manage(obj); 
          obj = Staffs[obj.getIndex()]; 
          selectRoute(obj); 
      } 
      else if (route == "help" || route == "h"){ 
          help("routes"); 
          selectRoute(obj); 
      } 
      else if (route == "q"){ 
          //pass to search 
      } 
      else{ 
          printer("invcm"); 
          selectRoute(obj); 
      } 
  } 
  
 
  
   void _search(){ 
      print("\n\nSearch >> "); 
      string command = lower(inputStr("")); 
      cin.clear(); 
      if (command == "s" || command == "student"){ 
          student found; 
          printer("sb"); 
          string s = lower(inputStr("\n\nSearch by > ")); 
          while(s != "id" && s != "name"){ 
              printer("invsb"); 
              s = lower(inputStr("\n\nSearch by  > ")); 
          } 
          if (s == "id"){ 
              printer("enterid"); 
              int val = inputInt(""); 
              while (val - stu_ID < 0 && stu_ID - val > 0){ 
                  printer("invid"); 
                  printer("enterid"); 
                  val = inputInt(""); 
              } 
              found = searchStudent(val); 
          } 
          else if (s == "name"){ 
              printer("entername"); 
              cin.ignore();string val = getStr(""); 
              found = searchStudent(val); 
          } 
          else{ 
              printer("invcm"); 
              _search(); 
          } 
          if (found.getStatus() != "null"){ 
              if (helptips == 1){ 
                  help("routes"); 
              } 
              selectRoute(found); 
          } 
          _search(); 
      } 
      else if (command == "l" || command == "staff"){ 
          staff found; 
          print("\n\n"); 
          printer("sb"); 
          string s = lower(inputStr("\n\nSearch by > ")); 
          while(s != "id" && s != "name"){ 
              printer("invsb"); 
              s = lower(inputStr("\n\nSearch by  > ")); 
          } 
          if (s == "id"){ 
              printer("enterid"); 
              int val = inputInt(""); 
              while (val - sta_ID < 0 && sta_ID - val > 0){ 
                  printer("invid"); 
                  printer("enterid"); 
                  val = inputInt(""); 
              } 
              found = searchStaff(val); 
          } 
          else if (s == "name"){ 
              printer("entername"); 
              cin.ignore();string val = getStr(""); 
              found = searchStaff(val); 
          } 
          else{ 
              printer("sm"); 
              _search(); 
          } 
          if (found.getStatus() != "null"){ 
              if (helptips == 1){ 
                  help("routes"); 
              } 
              selectRoute(found); 
          } 
          _search(); 
      } 
      else if (command == "d" || command == "department"){ 
          printer("chol"); 
          listItems(DEP_CODES);print("\n"); 
          string s = inputStr("\nSearch by > "); 
          if (lower(s) != "ldc"){ 
              Department found = searchDepartments(upper(s)); 
              if (helptips == 1 && found.dep_code != "null"){ 
                  help("exploredep"); 
              } 
              explore(found, "new"); 
          }else{ 
              print("\n\n");listItems(DEP_CODES);print("\n"); 
          } 
          _search(); 
      } 
      else if (command == "help" || command == "h"){ 
         help("search"); 
         _search(); 
      } 
      else if (command == "q"){ 
          //pass to end help 
      } 
      else{ 
          printer("invh"); 
          _search(); 
      } 
  } 
  
 
  
 
  void _remove(){ 
      print("\n\nRemove >> "); 
      string command = lower(inputStr("")); 
      cin.clear(); 
      if (command == "s" || command == "student"){ 
          student found; 
          printer("sb"); 
          string s = lower(inputStr("\n\nSearch by > ")); 
          while(s != "id" && s != "name"){ 
              printer("invsb"); 
              s = lower(inputStr("\n\nSearch by  > ")); 
          } 
          if (s == "id"){ 
              printer("enterid"); 
              int val = inputInt(""); 
              while (val - stu_ID < 0 && stu_ID - val > 0){ 
                  printer("invid"); 
                  printer("enterid"); 
                  val = inputInt(""); 
              } 
              found = searchStudent(val); 
          } 
          else if (s == "name"){ 
              printer("entername"); 
              cin.ignore();string val = getStr(""); 
              found = searchStudent(val); 
          } 
          else{ 
              printer("invcm"); 
              _remove(); 
          } 
          if (found.getStatus() != "null"){ 
              _remove(found); 
          } 
          _remove(); 
      } 
      else if (command == "l" || command == "staff"){ 
          staff found; 
          print("\n\n"); 
          printer("sb"); 
          string s = lower(inputStr("\n\nSearch by > ")); 
          while(s != "id" && s != "name"){ 
              printer("invsb"); 
              s = lower(inputStr("\n\nSearch by  > ")); 
          } 
          if (s == "id"){ 
              printer("enterid"); 
              int val = inputInt(""); 
              while (val - sta_ID < 0 && sta_ID - val > 0){ 
                  printer("invid"); 
                  printer("enterid"); 
                  val = inputInt(""); 
              } 
              found = searchStaff(val); 
          } 
          else if (s == "name"){ 
              printer("entername"); 
              cin.ignore();string val = getStr(""); 
              found = searchStaff(val); 
          } 
          else{ 
              printer("sm"); 
              _remove(); 
          } 
          if (found.getStatus() != "null"){ 
              _remove(found); 
          } 
          _remove(); 
      } 
      else if (command == "d" || command == "department"){ 
          printer("chol"); 
          listItems(DEP_CODES);print("\n"); 
          string s = inputStr("\nSearch by > "); 
          if (lower(s) != "ldc"){ 
              Department found = searchDepartments(upper(s)); 
              _remove(found); 
          }else{ 
              print("\n\n");listItems(DEP_CODES);print("\n"); 
          } 
          _remove(); 
      } 
      else if (command == "help" || command == "h"){ 
         help("remove"); 
         _remove(); 
      } 
      else if (command == "q"){ 
          //pass to end help 
      } 
      else{ 
          printer("invh"); 
          _remove(); 
      } 
  } 
  
 
  
 
  void _edit(){ 
      print("\n\nEdit >> "); 
      string command = lower(inputStr("")); 
      cin.clear(); 
      if (command == "s" || command == "student"){ 
          student found; 
          printer("sb"); 
          string s = lower(inputStr("\n\nSearch by > ")); 
          while(s != "id" && s != "name"){ 
              printer("invsb"); 
              s = lower(inputStr("\n\nSearch by  > ")); 
          } 
          if (s == "id"){ 
              printer("enterid"); 
              int val = inputInt(""); 
              while (val - stu_ID < 0 && stu_ID - val > 0){ 
                  printer("invid"); 
                  printer("enterid"); 
                  val = inputInt("");
			                } 
              found = searchStudent(val); 
          } 
          else if (s == "name"){ 
              printer("entername"); 
              cin.ignore();string val = getStr(""); 
              found = searchStudent(val); 
          } 
          else{ 
              printer("invcm"); 
              _edit(); 
          } 
          if (found.getStatus() != "null"){ 
              if (helptips == 1){ 
                  help("editstudent"); 
              } 
              _edit(found); 
          } 
          _edit(); 
      } 
      else if (command == "l" || command == "staff"){ 
          staff found; 
          print("\n\n"); 
          printer("sb"); 
          string s = lower(inputStr("\n\nSearch by > ")); 
          while(s != "id" && s != "name"){ 
              printer("invsb"); 
              s = lower(inputStr("\n\nSearch by  > ")); 
          } 
          if (s == "id"){ 
              printer("enterid"); 
              int val = inputInt(""); 
              while (val - sta_ID < 0 && sta_ID - val > 0){ 
                  printer("invid"); 
                  printer("enterid"); 
                  val = inputInt(""); 
              } 
              found = searchStaff(val); 
          } 
          else if (s == "name"){ 
              printer("entername"); 
              cin.ignore();string val = getStr(""); 
              found = searchStaff(val); 
          } 
          else{ 
              printer("sm"); 
              _edit(); 
          } 
          if (found.getStatus() != "null"){ 
              if (helptips == 1){ 
                  help("editstaff"); 
              } 
              _edit(found); 
          } 
          _edit(); 
      } 
      else if (command == "d" || command == "department"){ 
          printer("chol"); 
          listItems(DEP_CODES);print("\n"); 
          string s = inputStr("\nSearch by > "); 
          if (lower(s) != "ldc"){ 
              Department found = searchDepartments(upper(s)); 
              if (helptips == 1){ 
                  help("exploredep"); 
              } 
              _edit(found); 
          }else{ 
              print("\n\n");listItems(DEP_CODES);print("\n"); 
          } 
          _edit(); 
      } 
      else if (command == "help" || command == "h"){ 
         help("edit"); 
         _edit(); 
      } 
      else if (command == "q"){ 
          //pass to end help 
      } 
      else{ 
          printer("invh"); 
          _edit(); 
      } 
  } 
  
 
  
 
  void _records(){ 
      print("\n\nRecords >> "); 
      string command = lower(inputStr("")); 
      cin.clear(); 
      if (command == "s" || command == "student"){ 
          student found; 
          printer("sb"); 
          string s = lower(inputStr("\n\nSearch by > ")); 
          while(s != "id" && s != "name"){ 
              printer("invsb"); 
              s = lower(inputStr("\n\nSearch by > ")); 
          } 
          if (s == "id"){ 
              printer("enterid"); 
              int val = inputInt(""); 
              while (val - stu_ID < 0 && stu_ID - val > 0){ 
                  printer("invid"); 
                  printer("enterid"); 
                  val = inputInt(""); 
              } 
              found = searchStudent(val); 
          } 
          else if (s == "name"){ 
              printer("entername"); 
              cin.ignore();string val = getStr(""); 
              found = searchStudent(val); 
          } 
          else{ 
              printer("invcm"); 
              _records(); 
          } 
          if (found.getStatus() != "null"){ 
              if (helptips == 1){ 
                  help("records"); 
              } 
              _records(found); 
          } 
          _records(); 
      } 
      else if (command == "help" || command == "h"){ 
         help("find"); 
         help("records"); 
         _records(); 
      } 
      else if (command == "q"){ 
          //pass to end help 
      } 
      else{ 
          printer("invh"); 
          _records(); 
      } 
  } 
  
 
  void _manage(){ 
      print("\n\nManage >> "); 
      string command = lower(inputStr("")); 
      cin.clear(); 
      if (command == "s" || command == "student"){ 
          student found; 
          printer("sb"); 
          string s = lower(inputStr("\n\nSearch by > ")); 
          while(s != "id" && s != "name"){ 
              printer("invsb"); 
              s = lower(inputStr("\n\nSearch by  > ")); 
          } 
          if (s == "id"){ 
              printer("enterid"); 
              int val = inputInt(""); 
              while (val - stu_ID < 0 && stu_ID - val > 0){ 
                  printer("invid"); 
                  printer("enterid"); 
                  val = inputInt(""); 
              } 
              found = searchStudent(val); 
          } 
          else if (s == "name"){ 
              printer("entername"); 
              cin.ignore();string val = getStr(""); 
              found = searchStudent(val); 
          } 
          else{ 
              printer("invcm"); 
              _manage(); 
          } 
          if (found.getStatus() != "null"){ 
              if (helptips == 1){ 
                  help("manage"); 
              } 
              _manage(found); 
          } 
          _manage(); 
      } 
      else if (command == "help" || command == "h"){ 
        help("find"); 
         help("manage"); 
         _manage(); 
      } 
      else if (command == "q"){ 
          //pass to end help 
      } 
      else{ 
          printer("invh"); 
          _manage(); 
      } 
  } 
  
 
  void _settings(string command){ 
      if (command == ""){ 
          cin.clear(); 
          print("\n\nSetting >> "); 
          string command = lower(inputStr("")); 
          if (command == "nextsem" || command == "n"){ 
  //          set move to next semester /year 
              printer("choice");string ans = choice(); 
              if (ans == "y"){ 
                  if (semester == 1){ 
                      semester = 2; 
                  } 
                  else{ 
                      semester = 1; 
                      year += 1; 
                  } 
                  int len = Students.size(); 
                  for (int i=0;i<len;i++){ 
                     Students[i].moveSemester(); 
                  } 
                  printer("movesem"); 
                  _settings(""); 
             } 
          } 
          else if (command == "wipe" || command == "w"){ 
              printer("choice");string ans = choice(); 
              if (ans == "y"){ 
                 Students.clear(); 
                 Staffs.clear(); 
                 DEPARTMENTS.clear(); 
                 DEP_CODES.clear(); 
                 system("CLS"); 
                 _start(""); 
              } 
          } 
          else if (command == "start" || command == "s"){ 
              printer("choice");string ans = choice(); 
              if (ans == "y"){ 
                 _settings("start"); 
                 _settings(""); 
              } 
          } 
          else if (command == "tips" || command == "t"){ 
              printer("helptips"); 
              string ans = choice(); 
              if (ans == "y"){ 
                  helptips = 1; 
              } 
              else{ 
                  helptips = 0; 
              } 
          } 
          else if (command == "help" || command == "h"){ 
             help("settings"); 
             _settings(""); 
          } 
          else if (command == "q"){ 
              //pass to end help 
          } 
          else{ 
              printer("invh"); 
              _settings(""); 
          } 
      } 
      else if (command == "start"){ 
          printer("welcome"); 
          printer("enty"); 
          year = inputInt(""); 
          while (year < 2018){ 
              printer("inventy"); 
              year = inputInt(""); 
          } 
          printer("ents"); 
          semester = inputInt(""); 
          while (semester != 1 && semester != 2){ 
              printer("ents"); 
              semester = inputInt(""); 
          } 
          printer("helptips"); 
          string ans = choice(); 
          if (ans == "y"){ 
              helptips = 1;           } 
      } 
  } 
  
 
  
 
  void _readme(){ 
      system("notepad readme.txt"); 
  } 
  
 
  void _start(string s){ 
      if (semester == 0){ 
          printer("start"); 
         _settings("start"); 
          system("CLS");//system("clear"); 
      } 
      printer("start"); 
      if (s == "new"){ 
          printer("commands"); 
      } 
      engine(); 
  } 
  
 
  
 
  string engine(){ 
      cin.clear(); 
      print("\n\nEnter A Command >>>> "); 
      string command = lower(inputStr("")); 
      if (command == "commands"){ 
          printer("commands"); 
          engine(); 
     } 
      else if (command == "help" || command == "h"){ 
          printer("help"); 
          help(""); 
          engine(); 
      } 
      else if (command == "add"){ 
          if (helptips == 1){ 
              help("add"); 
          } 
          _add(); 
          engine(); 
      } 
      else if (command == "edit"){ 
          if (helptips == 1){ 
              help("edit"); 
          } 
         _edit(); 
          engine(); 
      } 
      else if (command == "remove"){ 
          if (helptips == 1){ 
              help("remove"); 
          } 
          _remove(); 
          engine(); 
      } 
      else if (command == "list"){ 
          if (helptips == 1){ 
             help("list"); 
          } 
          _list(); 
          engine(); 
      } 
      else if (command == "records"){ 
          if (helptips == 1){ 
              help("find"); 
          } 
         _records(); 
          engine(); 
      } 
      else if (command == "manage"){ 
          if (helptips == 1){ 
              help("find"); 
          } 
          _manage(); 
          engine(); 
      } 
      else if (command == "settings"){ 
          if (helptips == 1){ 
              help("settings"); 
          } 
          _settings(""); 
          engine(); 
      } 
      else if (command == "search"){ 
          if (helptips == 1){ 
              help("search"); 
          } 
          _search(); 
          engine(); 
      } 
      else if (command == "clear"){ 
          system("CLS");//system("clear"); 
          _start(""); 
      } 
      else if (command == "readme"){ 
         _readme(); 
          engine(); 
      } 
      else if (command == "exit"){ 
          exit(); 
     } 
      else{ 
          printer("invh"); 
          engine(); 
      } 
      return "done"; 
  } 

