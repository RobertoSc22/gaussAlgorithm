#include <iostream>
#include <cstring>
#define N 5
#define M 6

using namespace std;


float matrix[N][M];
int rows;
int columns;
void dimMatrix(int& , int&);
void insertMatrix(int& , int&);
void aggiungiUno(int& , int&);
void printMatrix(int& ,int&);
void reduceMatrix23(int& , int& );
void reduceMatrix34(int&, int&);

int main() {
	int stop = 0;
	do{
	cout<<"#######################################################################"<<endl;
    cout<<"**********Gauss algorithm**********************************************"<<endl;
    cout<<"#######################################################################"<<endl;
	dimMatrix(rows, columns);
	insertMatrix(rows, columns);
	printMatrix(rows, columns);
	if(rows == 2 && columns == 3){
	reduceMatrix23(rows, columns);
}
   if(rows == 3 && columns == 4){
	reduceMatrix34(rows, columns);
}
cout<<endl<<endl;
cout<<"##MENU##"<<endl;
cout<<"--0: New Matrix---------------"<<endl;
cout<<"--1: Arrest the Program-------"<<endl;
do{
cout<<"Select: ";
cin>>stop;
if(stop != 1 && stop != 0){
	cout<<"/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|Value Not Available"<<endl<<endl;
}
}while(stop != 1 && stop != 0);
}while(stop != 1);
cout<<endl<<endl;
cout<<"----End of Program Execution------------------------------------------------";
}

void dimMatrix(int& rows, int& columns){
	do{
		cout<<endl<<endl;
	cout << "Enter the number of rows in the matrix: ";
	cin >> rows;
	cout << "Enter the number of columns in the matrix: ";
	cin >> columns;
	if(rows == 2 && columns == 3){	
	}
	if(rows == 3 && columns == 4){
	}
	else{
		cout<<"Unsupported matrix format"<<endl<<endl;
	}
}while((rows != 2 || columns != 3) && (rows != 3 || columns != 4));
	cout << "The Matrix inserted is " << rows << " X " << columns << endl;
}

void insertMatrix(int& rows, int& columns) {
	matrix[rows][columns];
	cout<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<"Insert value matrix["<<i+1<<"]["<<j+1<<"]: ";
			cin>>matrix[i][j];
		}
	}
    matrix[rows][columns];
}

void printMatrix(int& rows, int& columns){
	cout<<endl<<endl;
	cout<<"Inserted matrix: "<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
}

void reduceMatrix23(int& rows, int& columns){
	if((matrix[0][0] != 0) && (matrix[1][0] != 0)){
		 matrix[1][1] = matrix[0][1] - ((matrix[0][0]*matrix[1][1])/matrix[1][0]);
		 matrix[1][2] = matrix[0][2] - ((matrix[0][0]*matrix[1][2])/matrix[1][0]);
		 matrix[1][0] = 0;
		 cout<<endl<<endl;	
		 cout<<"Reduced Matrix: "<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
		 
	}else{
		cout<<"The Matrix is already reduced: "<<endl<<endl;
	}
}

void reduceMatrix34(int& rows, int& columns){
	/*Se i primi numeri di ogni riga sono != 0*/
	if((matrix[0][0] != 0) && (matrix[1][0] != 0) && (matrix[2][0] != 0)){
		/*Riduco la seconda riga*/
		 matrix[1][1] = matrix[0][1] - ((matrix[0][0]*matrix[1][1])/matrix[1][0]);
		 matrix[1][2] = matrix[0][2] - ((matrix[0][0]*matrix[1][2])/matrix[1][0]);
		 matrix[1][3] = matrix[0][3] - ((matrix[0][0]*matrix[1][3])/matrix[1][0]);
		 matrix[1][0] = 0;
		 /*Riduco la terza riga*/
		 matrix[2][1] = matrix[0][1] - ((matrix[0][0]*matrix[2][1])/matrix[2][0]);
		 matrix[2][2] = matrix[0][2] - ((matrix[0][0]*matrix[2][2])/matrix[2][0]);
		 matrix[2][3] = matrix[0][3] - ((matrix[0][0]*matrix[2][3])/matrix[2][0]);
		 matrix[2][0] = 0;
		 cout<<endl<<endl;	
		 cout<<"Partially reduced Matrix: "<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
	if((matrix[1][1] != 0) && (matrix[2][1] != 0)){
		 matrix[2][2] = matrix[1][2] - ((matrix[1][1]*matrix[2][2])/matrix[2][1]);
		 matrix[2][3] = matrix[1][3] - ((matrix[1][1]*matrix[2][3])/matrix[2][1]);
		 matrix[2][1] = 0;
		 cout<<endl<<endl;	
		 cout<<"Reduced matrix: "<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
	}
}
/*Se i primi numeri della seconda e terza riga sono == 0*/
else if((matrix[0][0] != 0) && (matrix[1][0] == 0) && (matrix[2][0] == 0)){
	if((matrix[1][1] != 0) && (matrix[2][1] != 0)){
		 matrix[2][2] = matrix[1][2] - ((matrix[1][1]*matrix[2][2])/matrix[2][1]);
		 matrix[2][3] = matrix[1][3] - ((matrix[1][1]*matrix[2][3])/matrix[2][1]);
		 matrix[2][1] = 0;
		 cout<<endl<<endl;	
		 cout<<"Reduced matrix: "<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
	}
}
/*Se i primi numeri della prima e seconda riga sono != 0*/
else if((matrix[0][0] != 0) && (matrix[1][0] != 0) && (matrix[2][0] == 0)){
	/*Riduco la seconda riga*/
		 matrix[1][1] = matrix[0][1] - ((matrix[0][0]*matrix[1][1])/matrix[1][0]);
		 matrix[1][2] = matrix[0][2] - ((matrix[0][0]*matrix[1][2])/matrix[1][0]);
		 matrix[1][3] = matrix[0][3] - ((matrix[0][0]*matrix[1][3])/matrix[1][0]);
		 matrix[1][0] = 0;
		 cout<<endl<<endl;	
		 cout<<"Partially reduced Matrix: "<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
	if((matrix[1][1] != 0) && (matrix[2][1] != 0)){
		 matrix[2][2] = matrix[1][2] - ((matrix[1][1]*matrix[2][2])/matrix[2][1]);
		 matrix[2][3] = matrix[1][3] - ((matrix[1][1]*matrix[2][3])/matrix[2][1]);
		 matrix[2][1] = 0;
		 cout<<endl<<endl;	
		 cout<<"Reduced matrix: "<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
	}
}
	else{
		cout<<"The matrix is already reduced"<<endl<<endl;
	}

}



