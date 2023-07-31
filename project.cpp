#include <stdio.h>
#define V 5
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ---------------------------------------------------------- //
// ------------------- Methods Being Used ------------------- //

void initilize();
void initilizeBool();
void addEdge();
void addWeight();
void printAdjMatrix();
void printBoolArray();
void initilizeInt();
void print1D();
int* dijkstra(int arr[][V], int starting);

// -------------- Project Essentials -------------- //
bool Admin(string name, string password);
int shortestWay(int start, int drop);
void locations();
int travelCost(int start, int drop);
int roomCost(int seater);
void giveFeedBack();
void contactUS();
void hotelMenu();
int getIndex(string location);
void bookTicket();
string convertToUpperCase(string message);
void update_Receipt(string firstName);
void viewFeedBack();

struct receipt{

    string startLocation;
    string dropLocation;
    int travelTime;
    int roomBeds;
    int stayTime;
    int roomCost;
    int travelCost;
    
    receipt *next = NULL;
    
};

struct feedBack{

    char *travelExp;
    char *hotelExp;
    char *review;

    feedBack *next = NULL;
};

struct personalInfo{

    string firstName;
    string lastName;
    string phone;
    string cnic;
    string address;
    
    receipt *r_next = NULL;
    feedBack *s_next = NULL;
    personalInfo *next = NULL;
    
};

personalInfo *frontPF = NULL;
personalInfo *backPF = NULL;

struct queue{

	string firstName;
	
	queue *next = NULL;

};

queue *frontQ = NULL;
queue *backQ = NULL;

// ---------------------------------------------- //
// ---------------------------------------------- //
bool isEmptyQueue(){
    if(frontQ == NULL){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(string firstName){

    queue *current = new queue;

   	current -> firstName = firstName;

    if(isEmptyQueue()){
        frontQ = backQ = current;
        cout << "Your request has been sent" << endl;
    }
    else{
        backQ -> next = current;
        backQ = current;
        cout << "Your request has been sent" << endl;
    }
}
string dequeue(){
			
	string name;
    queue *p = new queue();
		
    if(isEmptyQueue()){
        cout << "\nAlready empty! Can't delete more" << endl; 
    }
    else{
       	name = frontQ -> firstName;
		p = frontQ -> next;
        delete frontQ;
        frontQ = p;
    }

	return name;
}
// ---------------------------------------------- //
// ---------------------------------------------- //
bool isEmptyPF(){
    if(frontPF == NULL){
        return true;
    }
    else{
        return false;
    }
}
void insert_PF(string firstName, string lastName, string phone, string cnic, string address){

    personalInfo *current = new personalInfo();
    
    current -> firstName = firstName;
    current -> lastName = lastName;
    current -> phone = phone;
    current -> cnic = cnic;
    current -> address = address;
    
    if(isEmptyPF()){
        frontPF = backPF = current;
    }
    else{
        backPF -> next = current;
        backPF = current;
    }
}
void displayPersonal(string firstName){
    personalInfo *p = frontPF;
    
    while (!isEmptyPF() && p -> firstName != firstName && p != NULL){
        p = p -> next;
        if (p == NULL) {
            break;
        }
    }
    
    if (p == NULL || isEmptyPF()) {
        cout << "No such data exists!" << endl;
    }
    else{
        if(isEmptyPF()){
            cout << "No record!" << endl;
        }
        else{
            cout << "\n-------------------------------------------------- PERSONAL INFO --------------------------------------------------\n" << endl;
            cout << "First Name\t\tLast Name\t\tPhone\t\t\tCNIC\t\t\tAddress";
            cout << "\n-------------------------------------------------------------------------------------------------------------------" << endl;

            string fname = p -> firstName;
            string lName = p -> lastName;
            string ph = p -> phone;
            string Cnic = p -> cnic;
            string add = p -> address;
            // ---------------------------------------- // 
            if(fname.length() < 9){
                int space = 9 - fname.length();
                string stuff(space, ' ');
                cout << p -> firstName + stuff << "\t\t";
            }
            else{
                cout << p -> firstName << "\t\t";    
            }
            // ---------------------------------------- //
            if(lName.length() < 9){
                int space = 9 - lName.length();
                string stuff(space, ' ');
                cout << p -> lastName + stuff << "\t\t";
            }
            else{
                cout << p -> lastName << "\t\t";    
            }
            // ---------------------------------------- //
            if(ph.length() < 9){
                int space = 9 - ph.length();
                string stuff(space, ' ');
                cout << p -> phone + stuff << "\t\t";
            }
            else{
                cout << p -> phone << "\t\t";    
            }
            // ---------------------------------------- //
            if(Cnic.length() < 9){
                int space = 9 - Cnic.length();
                string stuff(space, ' ');
                cout << p -> cnic + stuff << "\t\t";
            }
            else{
                cout << p -> cnic << "\t\t";    
            }
            // ---------------------------------------- //
            if(add.length() < 9){
                int space = 9 - add.length();
                string stuff(space, ' ');
                cout << p -> address + stuff << "\t\t";
            }
            else{
                cout << p -> address << "\t\t";    
            }

            cout << endl;
        }  
    }
}
// ---------------------------------------------- //
// ---------------------------------------------- //
void insertFeedBack(string firstName, char travelExp[100], char hotelExp[100], char review[100]){
    personalInfo *p = frontPF;
    feedBack *p3;
    feedBack *fb = new feedBack();
    
    fb -> travelExp = travelExp;
    fb -> hotelExp = hotelExp;
    fb -> review = review;
    
    while (!isEmptyPF() && p -> firstName != firstName && p != NULL){
        p = p -> next;
        if (p == NULL) {
            break;
        }
    }
    
    if(p == NULL){
        cout << "Person doesn't exist!" << endl;
    }
    else{
        if(p -> s_next == NULL){
            p -> s_next = fb;
        }
        else{
            feedBack *p2 = p -> s_next;
            while(p2 != NULL){
                p3 = p2;
                p2 = p2 -> next;
            }
            p3 -> next = fb;
        }
    }
    
}
void displayFB(string firstName){
    
    personalInfo *p = frontPF;

    while (!isEmptyPF() && p -> firstName != firstName && p != NULL){
        p = p -> next;
        if (p == NULL) {
            break;
        }
    }

    if(p == NULL || isEmptyPF()){
        cout << "Person doesn't exist!" << endl;
    }
    else{
        if(p -> s_next == NULL){
            cout << "No record!" << endl;

        }
        else{

            feedBack *p2 = p -> s_next;
            while (p2 != NULL)
            {    
                cout << "\n--------------- FeedBack ---------------\n" << endl;
                cout << "Travel Experience" << endl;
                cout << p2->travelExp << endl;
                cout << "\n" << endl;
                cout << "Hotel Experience" << endl;
                cout << p2 -> hotelExp << endl;
                cout << "\n" << endl;
                cout << "Rating" << endl;
                cout << p2 -> review << endl;
                
                // Moving forward  
                p2 = p2 -> next;
            }   
        }
    }    
}
// ---------------------------------------------- //
// ---------------------------------------------- //
void insert_Receipt(string firstName, string startLocation, string dropLocation, int travelTime, int roomBeds, int stayTime, int roomCost, int travelCost){

    personalInfo *p = frontPF;
    receipt *p3;
    receipt *current = new receipt();
    
    current -> startLocation = startLocation;
    current -> dropLocation = dropLocation;
    current -> travelTime = travelTime;
    current -> roomBeds = roomBeds;
    current -> stayTime = stayTime;
    current -> roomCost = roomCost;
    current -> travelCost = travelCost;
    
    while (!isEmptyPF() && p -> firstName != firstName && p != NULL){
        p = p -> next;
        if (p == NULL) {
            break;
        }
    }

    if (p == NULL) {
        cout << "No such person exists!" << endl; 
    }
    else{    
        if(p -> r_next == NULL){
            p -> r_next = current;
        }
        else{
            receipt *p2 = p -> r_next;
            while(p2 != NULL){
                p3 = p2;
                p2 = p2 -> next;
            }
            p3 -> next = current;
        }
    }
    

}
void display_Receipt(string firstName){
    personalInfo *p = frontPF;

    while (!isEmptyPF() && p -> firstName != firstName && p != NULL){
        p = p -> next;
        if (p == NULL) {
            break;
        }
    }

    if(p == NULL){
        cout << "Person doesn't exist!" << endl;
    }
    else{
        if(p -> r_next == NULL){
            cout << "No record!" << endl;

        }
        else{
            receipt *p2 = p -> r_next;
            cout << "\n----------------------------------------------------- RECEIPT -----------------------------------------------------\n" << endl;
            cout << "Departure\tArrival\t\tTime (Hours)\tRoom (Beds)\tStay Days\tRoom Cost\tTravel Cost";
            cout << "\n-------------------------------------------------------------------------------------------------------------------" << endl;
            while (p2 != NULL)
            {
                

                string start = p2 -> startLocation;
                string drop = p2 -> dropLocation;

                if(start.length() < 9){
                    int space = 9 - start.length();
                    string stuff(space, ' ');
                    cout << p2 -> startLocation + stuff << "\t";
                }
                else{
                    cout << p2 -> startLocation<< "\t";    
                }
                if(drop.length() < 9){
                    int space = 9 - drop.length();
                    string stuff(space, ' ');
                    cout << p2 -> dropLocation + stuff << "\t";
                }
                else{
                    cout << p2 -> dropLocation << "\t";    
                }
                
                printf("%-16d", p2 -> travelTime);
                printf("%-16d", p2 -> roomBeds);
                printf("%-16d", p2 -> stayTime);
                printf("%-16d", p2 -> roomCost);
                printf("%-16d", p2 -> travelCost);   

                p2 = p2 -> next;
                cout << "\n";    
            }
            
        }
    }
}
int total(string firstName){

    personalInfo *p =  frontPF;
    
    while (!isEmptyPF() && p -> firstName != firstName && p != NULL){
        p = p -> next;
        if (p == NULL) {
            break;
        }
    }
    
    if (p == NULL) {

        cout << "No such person exists" << endl;
    }
    else{
        receipt *t = p -> r_next;
        int total = 0;

        if(t == NULL){
            cout << "Don't work like that!" << endl;
        }
        else{

            while (t != NULL)
            {
                total += (t -> roomCost) + (t -> travelCost); 

                t = t -> next;
            }
        }

        return total;
    }
    return 0;

}
void update_Receipt(string firstName){

    personalInfo *p = frontPF;

    while (!isEmptyPF() && p -> firstName != firstName && p != NULL){
        p = p -> next;
        if (p == NULL) {
            break;
        }
    }

    if (p == NULL) {
        
        cout << "No such person exists" << endl;
    }
    else{

        receipt *upd = p -> r_next;

        if(upd == NULL){
            cout << "Data doesn't exit" << endl;
        }
        else{
            
            display_Receipt(firstName);
            
            string oldStart;
            cout << "\nEnter Old start location" << endl;
            cin >> oldStart;
            oldStart = convertToUpperCase(oldStart);
            
            string oldDrop;
            cout << "\nEnter Old drop location" << endl;
            cin >> oldDrop;
            oldDrop = convertToUpperCase(oldDrop);
            
            while (upd -> startLocation != oldStart && upd -> dropLocation != oldDrop && upd != NULL)
            {
                upd = upd -> next;
            }
            
            cout << "\nEnter new drop Location" << endl;
            string newLoation;
            cin >> newLoation;

            int sIndex = getIndex(oldStart);
            int dIndex = getIndex(newLoation);
            
            int time = shortestWay(sIndex, dIndex);
            int travel = travelCost(sIndex, dIndex);

            // all new data updated!
            upd -> dropLocation = newLoation;     
            upd -> travelTime = time;
            upd -> travelCost = travel;

            if(upd -> next != NULL){

                int sIndex = getIndex(newLoation);
                int dIndex = getIndex(upd -> next -> dropLocation);
                
                int time = shortestWay(sIndex, dIndex);
                int travel = travelCost(sIndex, dIndex);

                upd -> next -> startLocation = newLoation;     
                upd -> next -> travelTime = time;
                upd -> next -> travelCost = travel;

            }
        }
    }
};
void cancel(){
    
    personalInfo *p = frontPF;

    if (isEmptyQueue()){
        cout << "No person addded!" << endl;
    }
    else{
        string firstName = dequeue();
        while (!isEmptyPF() && p -> firstName != firstName && p != NULL){
            p = p -> next;
            if (p == NULL) {
                break;
            }
        }
        if (p == NULL) {
            cout << "Person doesn't exist" << endl;
        }
        else{
            receipt *del = p -> r_next;

            if (del == NULL) {

                cout << "No Data exists!!" << endl;
            }
            else{
                delete del;
                p -> r_next = NULL; // delete all user's data!
            }
        }
    }

    cout << "Data has been deleted!" << endl;
}
// ---------------------------------------------- //
// ---------------------------------------------- //
void displayALL(){
    personalInfo *p = frontPF;
    
    if (isEmptyPF()){
        cout << "Ain't no person exits!" << endl;
    }
    else{
        while (p != NULL){
            
            cout << "\n-------------------------------------------------- PERSONAL INFO --------------------------------------------------\n" << endl;
            cout << "First Name\t\tLast Name\t\tPhone\t\t\tCNIC\t\t\tAddress";
            cout << "\n-------------------------------------------------------------------------------------------------------------------" << endl;

            string fname = p -> firstName;
            string lName = p -> lastName;
            string ph = p -> phone;
            string Cnic = p -> cnic;
            string add = p -> address;
            // ---------------------------------------- // 
            if(fname.length() < 9){
                int space = 9 - fname.length();
                string stuff(space, ' ');
                cout << p -> firstName + stuff << "\t\t";
            }
            else{
                cout << p -> firstName << "\t\t";    
            }
            // ---------------------------------------- //
            if(lName.length() < 9){
                int space = 9 - lName.length();
                string stuff(space, ' ');
                cout << p -> lastName + stuff << "\t\t";
            }
            else{
                cout << p -> lastName << "\t\t";    
            }
            // ---------------------------------------- //
            if(ph.length() < 9){
                int space = 9 - ph.length();
                string stuff(space, ' ');
                cout << p -> phone + stuff << "\t\t";
            }
            else{
                cout << p -> phone << "\t\t";    
            }
            // ---------------------------------------- //
            if(Cnic.length() < 9){
                int space = 9 - Cnic.length();
                string stuff(space, ' ');
                cout << p -> cnic + stuff << "\t\t";
            }
            else{
                cout << p -> cnic << "\t\t";    
            }
            // ---------------------------------------- //
            if(add.length() < 9){
                int space = 9 - add.length();
                string stuff(space, ' ');
                cout << p -> address + stuff << "\t\t";
            }
            else{
                cout << p -> address << "\t\t";    
            }

            cout << endl;
            cout << endl;
            
            ///////////////////////////////////////////////////////
            // _________________________________________________ //
            
            receipt *p2 = p -> r_next;
            cout << "\n----------------------------------------------------- RECEIPT -----------------------------------------------------\n" << endl;
            cout << "Departure\tArrival\t\tTime (Hours)\tRoom (Beds)\tStay Days\tRoom Cost\tTravel Cost";
            cout << "\n-------------------------------------------------------------------------------------------------------------------" << endl;
            while (p2 != NULL)
            {
                

                string start = p2 -> startLocation;
                string drop = p2 -> dropLocation;

                if(start.length() < 9){
                    int space = 9 - start.length();
                    string stuff(space, ' ');
                    cout << p2 -> startLocation + stuff << "\t";
                }
                else{
                    cout << p2 -> startLocation<< "\t";    
                }
                if(drop.length() < 9){
                    int space = 9 - drop.length();
                    string stuff(space, ' ');
                    cout << p2 -> dropLocation + stuff << "\t";
                }
                else{
                    cout << p2 -> dropLocation << "\t";    
                }
                
                printf("%-16d", p2 -> travelTime);
                printf("%-16d", p2 -> roomBeds);
                printf("%-16d", p2 -> stayTime);
                printf("%-16d", p2 -> roomCost);
                printf("%-16d", p2 -> travelCost);   

                p2 = p2 -> next;
                cout << "\n";
            }

            ///////////////////////////////////////////////////////
            receipt *t = p -> r_next;
            int total = 0;

            if(t == NULL){
                cout << "Don't work like that!" << endl;
            }
            else{

                while (t != NULL)
                {
                    total += (t -> roomCost) + (t -> travelCost); 

                    t = t -> next;
                }
            }
            cout << "\nTotal cost is: " << total << endl;
            cout << endl;
            cout << endl;
            
            ///////////////////////////////////////////////////////
            // _________________________________________________ //
            
            feedBack *p3 = p -> s_next;
            while (p3 != NULL)
            {    
                cout << "\n--------------- FeedBack ---------------\n" << endl;
                cout << "Travel Experience" << endl;
                cout << p3->travelExp << endl;
                cout << "\n" << endl;
                cout << "Hotel Experience" << endl;
                cout << p3 -> hotelExp << endl;
                cout << "\n" << endl;
                cout << "Rating" << endl;
                cout << p3 -> review << endl;
                
                // Moving forward  
                p3 = p3 -> next;
            }
            
            cout << endl;
            cout << endl;
            
            ////// move to the next one ///
            p = p -> next;
            
        }
    }
}

// --------------------------------------------------- //
// ------------------- Main Method ------------------- //

int main() {

    int decision = -1;
    int choice = -1;
    
    while (decision != 0)
    {
        cout << "\n\n";
        cout << "\n--------------------------------------------------------------";
        cout << "\n\t\t\tAKKB TOURISM" << endl;
        cout << "--------------------------------------------------------------" << endl;
        
        cout << "\nSELECT YOUR OPTION!\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to Login as an Admin." << endl;
        cout << "Press [2] to Login as a user." << endl;
        cout << "-----------------------------" << endl;
                        
        cin >> decision;

        if (decision == 1) {
            bool check = true;
            while (check) {
                string userName;
                cout << "\nEnter your user name\n--------------------" << endl;
                cin >> userName;
                
                string password;
                cout << "\nEnter your password\n-------------------" << endl;
                cin >> password;    
                
                if (Admin(userName, password) == true) {
                    system("CLS");
                    while (choice != 3){
                        cout << "\n\n-------------\nWELCOME ADMIN\n-------------";
                        cout << "\n\n";
                        cout << "\n--------------------------------------------------------------";
                        cout << "\n\t\t\tAKKB TOURISM" << endl;
                        cout << "--------------------------------------------------------------" << endl;
                        
                        cout << "Press [1] to Display All Details." << endl;
                        cout << "Press [2] to Cancel Bookings." << endl;
                        cout << "Press [3] to return to the Main Menu" << endl;
                        cout << "------------------------------------" << endl;
                        
                        cin >> choice;
                        if(choice == 1){
                            system("CLS");
                            displayALL();
                        }
                        else if(choice == 2){
                            system("CLS");
                            cancel();
                        }
                        else if (choice == 3) {
                            system("CLS");
                            check = false;
                            break;
                        }
                    }
                }
                else{
                    system("CLS");
                    cout << "\nWrong email or passwork! Re-enter credientials!" << endl;
                }
            }
        }
        else if (decision == 2) {
            system("CLS");
            while (choice != 0) {
                cout << "\n\n";
                cout << "\n--------------------------------------------------------------";
                cout << "\n\t\t\tAKKB TOURISM" << endl;
                cout << "--------------------------------------------------------------" << endl;
        
                cout << "\nSELECT YOUR OPTION!\n\nPress [0] to Exit." << endl;
                cout << "Press [1] to Book Ticket." << endl;
                cout << "Press [2] to Display Receipt." << endl;
                cout << "Press [3] to Update Drop Location." << endl;
                cout << "Press [4] to Cancel Booking" << endl;
                cout << "Press [5] to See Hotel Menu" << endl;
                cout << "Press [6] to Give Feedback" << endl;
                cout << "Press [7] to contact Us" << endl;
                cout << "Press [8] to view Personal info" << endl;
                cout << "Press [9] to view FeedBack" << endl;
                cout << "Press [10] to Return to Main Menu" << endl;
                cout << "\n--------------------------------------------------------------" << endl;
                
                cin >> choice;


                if(choice == 1){
                    bookTicket();
                }
                else if(choice == 2){
                    system("CLS");
                    string firstName;
                    cout << "\nEnter your first Name" << endl;
                    cin >> firstName;
                    display_Receipt(firstName);
                    cout << "\nTotal cost is: " << total(firstName);
                }
                else if (choice == 3) {
                    system("CLS");
                    string firstName;
                    cout << "\nEnter your first Name" << endl;
                    cin >> firstName;
                    update_Receipt(firstName);
                }
                else if (choice == 4) {
                    system("CLS");
                    string firstName;
                    cout << "\nEnter your first Name" << endl;
                    cin >> firstName;
                    enqueue(firstName);
                    
                }
                else if (choice == 5) {
                    system("CLS");
                    hotelMenu();
                }
                else if (choice == 6) {
                    system("CLS");
                    giveFeedBack();
                }
                else if (choice == 7) {
                    system("CLS");
                    contactUS();
                }
                else if (choice == 8) {
                    system("CLS");
                    string firstName;
                    cout << "\nEnter your first Name" << endl;
                    cin >> firstName;
                    displayPersonal(firstName);
                }
                else if (choice == 9) {
                    system("CLS");
                    string name;
                    cout << "\nEnter your First Name!\n------------------------------" << endl;    
                    cin >> name;
                    displayFB(name);
                }
                else if (choice == 10) {
                    system("CLS");
                    break;
                }
                else{
                    system("CLS");
                }
            }        
        }
        else{
            system("CLS");
        }
    }
    return 0;

}

// ------------------- Graphs implementation ------------------- //
// Initialize the matrix to zero
void initilize(int arr[][V]) {
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
    }
    
}

void initilizeBool(bool arr[V]) {
    
    for (int i = 0; i < V; i++) {
        arr[i] = false;
    }
    
}

// Add edges
void addEdge(int arr[][V], int i, int j) {
    
    arr[i][j] = 1;

}
void addWeight(int arr[][V], int i, int j, int num) {

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if(arr[i][j] == 0 && i != j){
                arr[i][j] = -1;
            }
        }
    }    
    arr[i][j] = num;

}

// Print the matrix
void printAdjMatrix(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {

        for (j = 0; j < V; j++) {
            printf("%3d", arr[i][j]);
        }
        cout << "\n";
    }
    cout << "-----------------" << endl;
}

void printBoolArray(bool arr[V]) {
    int i;
    cout << "-----------------\n";
    for (i = 0; i < V; i++) {
        printf("%3d", arr[i]);

    }
}
void initilizeInt(int arr[V]) {
    
    for (int i = 0; i < V; i++) {
        arr[i] = 0;
    }
    
}
void print1D(int arr[V]) {
    int i;
    for (i = 0; i < V; i++) {
        printf("%3d", arr[i]);

    }
}

int* dijkstra(int arr[][V], int starting){
    
    bool vis[V];
    static int small[V];
    initilizeBool(vis);
    initilizeInt(small);

    int i = starting;

    int smallest = INT_MAX;
    int smallestIndex = 0; 
    
    int path = 0;
    int check = true;
    int right = true;

    while (true) {
        
        // checks visited nodes 
        for(int k = 0; k < V; k++){
            if(vis[k] != true){
                check = false;
                break;
            }
        }

        if(i == starting){
            // insert all the values at first
            for (int j = 0; j < V; j++){
                small[j] = arr[i][j];
            }
            vis[i] = true;
            
            // find the smallest value
            for (int j = 0; j < V; j++) {
                if(small[j] < smallest && small[j] != -1 && vis[j] != true){
                    smallest = small[j]; 
                    smallestIndex = j;
                }
            }
            // here found the smallest index and smallest value     
            /* ------------------------------------- */
            i = smallestIndex;
            path = smallest;
            smallest = INT_MAX;
        }        
        else{
            for (int j = 0; j < V; j++){
                
                if(vis[j] != true && i != j && arr[i][j] != -1){
                    
                    if(small[j] == -1){
                        small[j] = path + arr[i][j];
                    }
                    else if(path + arr[i][j] > small[j]){
                        continue;
                    }
                    else{
                        small[j] = path + arr[i][j];
                    }
                }
            }
            vis[i] = true;

            for (int j = 0; j < V; j++) {
                if(small[j] < smallest && small[j] != -1 && vis[j] != true){
                    smallest = small[j]; 
                    smallestIndex = j;
                }
            }   
            /* ------------------------------------- */
            i = smallestIndex;
            path = smallest;
            smallest = INT_MAX;
        }

        if(check == true){
            break;
        }
        check = true;
    }

    return small;

}

// ------------------- Rest implementation ------------------- //
bool Admin(string name, string password){
    string adminName = "inayat";
    string adminPass = "inayat007";

    if (name == adminName && password == adminPass) {
        return true;
    }
    else{
        return false;
    }
    return 0;
}
int shortestWay(int start, int drop){
    int adjMatrix[V][V];
    bool boolArr[V];

    initilize(adjMatrix);
    initilizeBool(boolArr);
    
    // distance ISB
    addWeight(adjMatrix, 0, 1, 5);
    addWeight(adjMatrix, 0, 2, 4);
    addWeight(adjMatrix, 0, 3, 6);
    addWeight(adjMatrix, 0, 4, 2);
    
    // distance Kashmir
    addWeight(adjMatrix, 1, 0, 5);
    addWeight(adjMatrix, 1, 2, 8);
    addWeight(adjMatrix, 1, 3, 7);
    addWeight(adjMatrix, 1, 4, 4);

    // distance swat
    addWeight(adjMatrix, 2, 0, 4);
    addWeight(adjMatrix, 2, 1, 8);
    addWeight(adjMatrix, 2, 3, 8);
    addWeight(adjMatrix, 2, 4, 5);
    
    // distance naran
    addWeight(adjMatrix, 3, 0, 6);
    addWeight(adjMatrix, 3, 1, 7);
    addWeight(adjMatrix, 3, 2, 8);
    addWeight(adjMatrix, 3, 4, 6);

    // distance murree
    addWeight(adjMatrix, 4, 0, 2);
    addWeight(adjMatrix, 4, 1, 4);
    addWeight(adjMatrix, 4, 2, 5);
    addWeight(adjMatrix, 4, 3, 6);

    // ----- Applying Dijkstra's algorithm ----- //
    // Shortest path from starting location! like:
    // say ISB: [0, 5, 4, 6, 2]

    
    int *ptr = dijkstra(adjMatrix, start);
    int hours = 0; 

    for(int i = 0; i < 5; i++){
        if(i == drop){
            hours = ptr[i];
            break;
        }
    }

    return hours;          
}
void locations(){

    string arr[5] = { "[0] ISLAMABAD", "[1] KASHMIR", "[2] SWAT", "[3] NARAN", "[4] MURREE" };
    
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }

}
int travelCost(int start, int drop){

    int price = 0;

    // [0] ISB
    // [1] Kashmir
    // [2] Swat
    // [3] Naran
    // [4] Murree
    int cost[5][5] = {
        {0, 1000, 2000, 2000, 500},
        {1000, 0, 2500, 2500, 1500},
        {2000, 2500, 0, 2500, 1700},
        {2000, 2500, 2000, 0, 1900},
        {500, 1000, 1000, 1900, 0}
    };

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == start && j == drop && i != j){
                price += cost[i][j];
                break; 
            }
        }
    }

    return price;
}
int roomCost(int seater){
    if(seater == 1){
        return 10000;
    }
    else if(seater == 2){
        return 15000;
    }
    else if(seater == 3){
        return 20000;
    }
    return 0;
}
void giveFeedBack(){
    string name;
    static char blank[100] = {0};
    static char travelExp[100] = {0};
    static char hotelExp[100] = {0};
    static char rating[100] = {0};
    
    cout << "\nEnter your First Name!\n------------------------------" << endl;    
    cin >> name;

    cin.getline(blank, 100);

    cout << "\nHow was your travel experience?\n------------------------------" << endl;    
    cin.getline(travelExp, 100);

    cout << "\nHow was your hotel experience?\n-----------------------------" << endl;    
    cin.getline(hotelExp, 100);

    cout << "\nGive Rating\n-----------" << endl;    
    cin.getline(rating, 100);

    cout << "\n\n";
    
    insertFeedBack(name, travelExp, hotelExp, rating);

}
void contactUS(){

    cout << "\n\n";
    cout << "------------------------\nContact Us\n------------------------\n" << endl;
    
    cout << "Our Email\n---------" << endl;
    cout << "abc@yahoo.com";
    
    cout << "\n" << endl;

    cout << "Phone Number\n----------------" << endl;
    cout << "+1-435-34534535";
    
    cout << "\n" << endl;

    cout << "Address\n-------" << endl;
    cout << "Comstas University Islamabad!\n* don't come *";
    
    cout << "\n" << endl;


}
void hotelMenu(){

    cout << "----------- Starter ------------\n" << endl;
    cout << "Chilli Cheese Fries          575" << endl;
    cout << "Cheese balls                 595" << endl;
    cout << "Buffalo Chicken Bites        600" << endl;
    cout << "Dynamite Prons               775" << endl;
    
    cout << "\n";

    cout << "------- Soups and Salads -------\n" << endl;
    cout << "Hot and Sour Soup            575" << endl;
    cout << "Chicken and Mushroom Soup    595" << endl;
    cout << "Chicken Jacket Salad         625" << endl;
    cout << "Chicken Millanese Salad      625" << endl;
    
    cout << "\n";

    cout << "---------- Main Course ---------\n" << endl;
    cout << "Grills Steaks               1095" << endl;
    cout << "Burgers and Sandwiches       725" << endl;
    cout << "Pizza                       1000" << endl;
    cout << "Pasta                        625" << endl;
    
    cout << "\n";

    cout << "------------ Drinks ------------\n" << endl;
    cout << "Coffee                       550" << endl;
    cout << "Tea                          200" << endl;
    cout << "Fresh Juice                  350" << endl;
    cout << "Soft Drinks                  150" << endl;
    
}
string convertToUpperCase(string message) {
    for (int i = 0; i < message.length(); ++i)
    {
        message[i] = toupper(message[i]);
    }
    return message;
}
int getIndex(string location){
    
    string loc = convertToUpperCase(location);

    string arr[5] = { "ISLAMABAD", "KASHMIR", "SWAT", "NARAN", "MURREE" };
    int index = -1;
    
    // getting start index
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == loc) {
            index = i;
            break;
        }
        
    }

    return index;
}
bool checkVisited(int arr[5], int num){
    int check = true;
    for (int i = 0; i < 5; i++)
    {
        if(arr[i] == num){
            check = false;
            break;
        }
    }
    return check;
}
void bookTicket(){


    string firstName;
    string lastName;
    string phoneNumber;
    string cnic;
    string address;

    cout << "\nEnter your First Name\n---------------------" << endl;    
    cin >> firstName;

    cout << "\nEnter your Last Name\n--------------------" << endl;    
    cin >> lastName;

    cout << "\nEnter your Phone Number\n-----------------------" << endl;    
    cin >> phoneNumber;

    cout << "\nEnter your CNIC Number\n----------------------" << endl;    
    cin >> cnic;

    cout << "\nEnter your Address\n------------------" << endl;    
    cin >> address;

    insert_PF(firstName, lastName, phoneNumber, cnic, address);
    int check = true;
    string arr[5] = { "ISLAMABAD", "KASHMIR", "SWAT", "NARAN", "MURREE"};

    int move = 0;
    int moveArray[5];
    cout << "\n";

    while (check){
        cout << "\n---------------------------------------------------\nPlease select any of the locations to start journey\n---------------------------------------------------" << endl;    
        locations();
        cout << "------------------------" << endl;
        
        int start;
        cin >> start;

        if(start >= 0 && start <= 4){

            while (true) {    
                cout << "\nPlease select your drop location\n------------------------" << endl;    
                locations();
                cout << "------------------------" << endl;
                int drop;
                cin >> drop;
                
                // checks if location has already been added!
                moveArray[move] = start;
                move++;        
                if(!checkVisited(moveArray, drop)){
                    cout << "------------------------\nStart & drop location same\n------------------------" << endl;
                    break;
                }
                else if (drop >= 0 && drop <= 4) {
                    
                    int bedChoice;
                    while (true) {
                        cout << "\nWhat Bedroom would you like to choose\n--------------------------------\nPress [1] to select single bed\nPress [2] to select double bed\nPress [3] to select triple bed\n------------------------" << endl;    
                        cin >> bedChoice;
                        
                        if(bedChoice >= 1 && bedChoice <= 3){
                            break;
                        }
                        system("CLS");
                        cout << "------------------------\nInvalid Bed Choice\n------------------------" << endl;
                
                    }
                    
                    
                    int daysChoice;
                    while (true) {
                        cout << "\nHow many days would you like to stay\n-------------------------------" << endl;    
                        cin >> daysChoice;

                        if(daysChoice > 0 && daysChoice <= 7){
                            break;
                        }    
                        system("CLS");
                        cout << "------------------------\nInvalid Stay Time\n------------------------" << endl;
                
                    }
                    
                    cout << "------------------------" << endl;
                    
                    string startLoc = arr[start];
                    string dropLoc = arr[drop];
                    int time = shortestWay(start, drop);
                    int room = roomCost(bedChoice) * daysChoice;
                    int travel = travelCost(start, drop);
                    
                    moveArray[move] = drop;
                    move++;
                    insert_Receipt(firstName, startLoc, dropLoc, time, bedChoice, daysChoice, room, travel);
                    
                    bool keepOnRunning = true;
                    int count = 0;
                    int saveDrop = start;
                    while (count <= 3 && keepOnRunning == true){
                        
                        int ask;
                        cout << "\n----------------------------------------------------\nWould you like to add any other location to the list\n----------------------------------------------------\nPress [ANY] for Yes\nPress [0] for NO\n------------------------" << endl;    
                        cin >> ask;    

                        
                        if(ask == 0){
                            break;
                        }

                        int nextDrop;
                        while (true) {
                            cout << "\nPlease select your drop location\n------------------------" << endl;    
                            locations();
                            cout << "------------------------" << endl;
                            
                            cin >> nextDrop;
                            if (nextDrop >= 0 && nextDrop <= 4){
                                break;
                            }
                            system("CLS");
                            cout << "------------------------\nInvalid drop location\n------------------------" << endl;  
                            
                        }
                        
                        if(!checkVisited(moveArray, nextDrop)){
                          cout << "------------------------\nLocation Already added\n------------------------" << endl;  
                        }
                        else if (nextDrop >= 0 && nextDrop <= 4) {
                            
                            while (true) {
                                cout << "\nWhat Bedroom would you like to choose\n--------------------------------\nPress [1] to select single bed\nPress [2] to select double bed\nPress [3] to select triple bed\n------------------------" << endl;    
                                cin >> bedChoice;
                                
                                if(bedChoice >= 1 && bedChoice <= 3){
                                    break;
                                }
                                system("CLS");
                                cout << "------------------------\nInvalid Bed Choice\n------------------------" << endl;
                        
                            }

                            while (true) {
                                cout << "\nHow many days would you like to stay\n------------------------" << endl;    
                                int daysChoice;
                                cin >> daysChoice;

                                if(daysChoice > 0 && daysChoice <= 7){
                                    break;
                                }    
                                system("CLS");
                                cout << "------------------------\nInvalid Stay Time\n------------------------" << endl;
                
                            }
                            cout << "------------------------" << endl;
                            
                            startLoc = arr[drop];
                            dropLoc = arr[nextDrop];
                            time = shortestWay(drop, nextDrop);
                            room = roomCost(bedChoice) * daysChoice;
                            travel = travelCost(drop, nextDrop);
                                                        
                            moveArray[move] = nextDrop;
                            move++;
                            insert_Receipt(firstName, startLoc, dropLoc, time, bedChoice, daysChoice, room, travel);

                            saveDrop = drop;
                            drop = nextDrop;
                            count++;
                        }
                        if(count == 3){
                            cout << "------------------------\nAll Locations added\n------------------------" << endl;  
                            break;
                        }
                    }
                
                    check = false;
                    break;
                            
                }
                else{
                    system("CLS");
                    cout << "------------------------\nInvalid drop location\n------------------------" << endl;
                }
            }
        }
        else{
            system("CLS");
            cout << "------------------------\nInvalid start location\n------------------------" << endl;
        }
    }

    cout << "------------------------------------------------------------------------" << endl;
        
    bool run = true;
    while (run) {
        int choice;
        cout << "\nHow would you like to pay?\n--------------------------\nPress [1] to pay in person [Ticket req.]\nPress [2] to pay as using credit card\n------------------------------------" << endl;
        cin >> choice;
        
        if(choice == 1){
            system("CLS");
            cout << "Successful" << endl;
            break;
        }
        else if(choice == 2){
            string number;
            while (true) {
                cout << "\nEnter a credit card number" << endl;
                cin >> number;

                if(number.length() == 16){
                    system("CLS");
                    cout << "-----------------\nPayment accepted!\n-----------------" << endl;
                    run = false;
                    break;
                }
            }
        }
        else {
            system("CLS");
            cout << "------------------------\nEnter the right choice\n------------------------" << endl;   
        }        
    }
}