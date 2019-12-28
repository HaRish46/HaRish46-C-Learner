/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
char* findCommomSub(char *str1, char *str2, int *len, int *inde, int max) {
	*len = 0;
	*inde = 0;
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	int n = strlen(str1);
	int m = strlen(str2);
	int a[2002][2002] = { 0 };
	int mx = 0, index = 0;
	int flag = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (str1[i - 1] == str2[j - 1]) {
				flag++;
				a[i][j] = a[i - 1][j - 1] + 1;
				if (mx < a[i][j]) {
					mx = a[i][j];
					index = i;
				}
			}
			else
				a[i][j] = 0;
		}
	}
	//printf("%d %d \n",mx,index);
	if (mx == 0 || mx<max)return NULL;
	//printf("%s %d %s %d\n",str1,n,str2,m);
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			;//printf("%d ",a[i][j]);
		}//printf("\n");
	}
	//printf("%d %d : ",index,mx);
	char *ans = (char *)malloc(sizeof(char)*m + n);
	int i;
	for (i = 0;i < mx;i++) {
		//printf("1 %c ",str1[i+index-mx]);
		ans[i] = str1[i + index - mx];

	}ans[i] = '\0';
	*len = mx;
	*inde = index;
	return ans;

}
int findcost(char *c) {
	if (c == NULL)return 0;
	int a = 0;//printf(" (cost %s )", c);
	for (int i = 0;c[i] != '\0';i++)
		a += (c[i] - 'A' + 1);
	//printf(" %d ", a);
	return a;
}
char * find_common_route(char * hacklist, char *codelist, int *cost) {
	int len = 0, index = 0;
	if (hacklist == NULL || codelist == NULL)return NULL;
	char *c;
	int max = 0;
	*cost = 0;
	char *ans = (char *)malloc(sizeof(char) * 100);
	int v = 0;
	while (hacklist) {
		c = findCommomSub(hacklist, codelist, &len, &index, max);
		if (v == 0 && len == 0)return NULL;
		v = 1;
		if (c == NULL)break;
		if (strlen(hacklist)>index)
			hacklist = hacklist + index;
		else break;
		if (max<len) {
			max = len;
			strcpy(ans, c);
		}
		else if (max == len) {
			if (strcmp(ans, c)>0) {
				strcpy(ans, c);
			}
		}

	}if (c != NULL&&max<len) {
		max = len;
		strcpy(ans, c);
	}
	else if (max == len) {
		if (strcmp(ans, c)>0) {
			strcpy(ans, c);
		}
	}

	*cost = findcost(ans);//printf(" %s %d ",ans,*cost);
	return ans;
}