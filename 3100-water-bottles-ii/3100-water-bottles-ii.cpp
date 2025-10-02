class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) { //nb=total number of bottles intinally ne=number of bottles
    //that can be exchanged
        int ans=nb; //sbse pehle we drink all the bottles
        int em=nb; //abi we have nb empty bottles
        while(em>=ne){
            em-=ne;
            ans++;
            em++; //jo bottle bhri lets say vo peeli so vo b empty
            ne++;
        }
        
        return ans;
    }
};