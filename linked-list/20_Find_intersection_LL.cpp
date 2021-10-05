// if two linked list have some common collection of node
// procedure - traverse from backward when we reach at point where two address are different
//             then it previous address will be intersection point

// how can we traverse backword ??
// using two stack (filled with address of linked nodes)
// poping out address until adress is same

// program code procedure

/*
    stack s1,s2;

    p = first_LL
    while(p) s1.push(p)

    p = second_LL
    while(p) s2.push(p)
    
    while(s1.top() == s2.top())
    {
        p = s1.pop(); // p --> last node delete from stack 
        s2.pop();
    }

    cout<<"Intersection point node = "<< p <<endl;
*/