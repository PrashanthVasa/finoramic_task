int Solution::braces(string A) {
    bool flag = false;
    int count;
    stack <int> store;
    for(int index = 0;A[index]!='\0';index++){
        if(A[index] == '('){
            store.push(0);
            count = 0;
        }
        else if(A[index] =='+' ||A[index] =='-' ||A[index] =='*' ||A[index] =='/'){
            if(!store.empty()){
                count = store.top();
                store.pop();
                store.push(count+1);
                
            }
        }
        else if(A[index] == ')'){
            if(!store.empty()){
                count = store.top();
                store.pop();
                if(count==0){
                    flag = true;
                    break;
                }  
            }
            else{
                flag = true;
                break;
            }
        }
        else{
            continue;
        }
    }
    return flag;
}
