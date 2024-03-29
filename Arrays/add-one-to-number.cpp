vector<int> Solution::plusOne(vector<int> &a) {
    int n = a.size(); 
    a[n-1] += 1; 
    int carry = a[n-1]/10; 
    a[n-1] = a[n-1] % 10; 
    for (int i=n-2; i>=0; i--) { 
        if (carry == 1) { 
           a[i] += 1; 
           carry = a[i]/10; 
           a[i] = a[i] % 10; 
        } 
    } 
    if (carry == 1)  a.insert(a.begin(), 1);
    while(a[0] == 0) a.erase(a.begin());
    return a;
} 
