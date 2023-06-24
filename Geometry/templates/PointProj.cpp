void proj(line<double>k, Point<double> st, Point<double> &ans){
    line<double>h(k.num, k.den, st);
    if(k.A == 0){ ans.x = st.x; ans.y = k.C; }
    else{
        if(k.B==0){ ans.x = -(k.C/k.A); ans.y = st.y; }
        else{
            ans.x = (k.b-h.b)/(h.a-k.a);
            ans.y = h.a*ans.x+h.b;
        }
    }
}
