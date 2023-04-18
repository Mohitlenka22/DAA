Algorithm DelMax(A, n, x)
{
//Delete the maximum from the heap A[1:n] and store it in x.
	x:= A[1]; 
	A[1]:= A[n];
	n:= n-1;	//Decrement the heap size
	Adjust(A, 1, n);
	return x;
}
Algorithm Adjust(A, i, n)
{
//The complete binary trees with roots 2i and 2i+1 are combined with node i to from a heap //rooted at i. No node has an address greater than n or less than 1.
	j:=2i;	//Left child of i
item:=A[i];
while(j<=n) do
{
	if((j<n) and (A[j]<A[j+1])) then   	// compare left and right child 
		j:= j+1;			//and let j be the right child.	
	if(item>=A[j]) then break;	//position for item is found which is j/2.
	A[j/2]:=A[j];	//move the A[j] up
	j:=2j;		//Left child of j
}
A[j/2]:=item;
}
