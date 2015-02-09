#include <stdio.h>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix;
Matrix readInput(){
	int row ,col;
	Matrix input;
	scanf("%d%d",&row,&col);
	input.resize(row);
	for( int i = 0 ; i != row ; ++i ){
		input[i].resize(col);
		for( int j = 0 ; j != col ; ++j ){
			scanf("%d",&input[i][j]);
		}
	}
	return input;
}
int dpOne( const Matrix& input, Matrix& dpFind , int i , int j ){
	if( dpFind[i][j] != -1 )
		return dpFind[i][j];
	int result = 1;
	if( i - 1 >= 0 && input[i][j] > input[i-1][j] ){
		int temp = dpOne(input,dpFind,i-1,j);
		if( temp + 1 > result )
			result = temp + 1;
	}
	if( j - 1 < input[i].size() && input[i][j] > input[i][j-1] ){
		int temp = dpOne(input,dpFind,i,j-1);
		if( temp + 1 > result )
			result = temp + 1;
	}
	if( i + 1 < input.size() && input[i][j] > input[i+1][j] ){
		int temp = dpOne(input,dpFind,i+1,j);
		if( temp + 1 > result )
			result = temp + 1;
	}
	if( j + 1 < input[i].size()  && input[i][j] > input[i][j+1] ){
		int temp = dpOne(input,dpFind,i,j+1);
		if( temp + 1 > result )
			result = temp + 1;
	}
	dpFind[i][j] = result;
	return result;
}
int dpAll( const Matrix& input ){
	Matrix dpFind = input;
	for( int i = 0 ; i != dpFind.size() ; ++i ){
		for( int j = 0 ; j != dpFind[i].size() ; ++j ){
			dpFind[i][j] = -1;
		}
	}
	int result = 0;
	for( int i = 0 ; i != dpFind.size() ; ++i ){
		for( int j = 0 ; j != dpFind[i].size() ; ++j ){
			int temp = dpOne(input,dpFind,i,j);
			if( temp > result )
				result = temp;
		}
	}
	return result;
}
void output( int result ){
	printf("%d",result);
}
int main(){
	Matrix input = readInput();
	int result = dpAll(input);
	output(result);
	return 0;
}
