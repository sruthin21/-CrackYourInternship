class Solution{
    public:
    int sameChar(string A, string B)
    {
        
        int count=0;
        for(int i=0; i<B.length(); i++)
        {
            if(isupper(A[i]))
                A[i] = tolower(A[i]);
            if(isupper(B[i]))
                B[i] = tolower(B[i]);
            if(A[i] == B[i])
                count++;
        }
        return count;
    }
};