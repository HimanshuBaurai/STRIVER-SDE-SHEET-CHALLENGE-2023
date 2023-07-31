int BASE=1e6;

vector<int> stringMatch(string text, string pattern) {
	vector<int>ans; 

	int textLen=text.length();
	int patternLen=pattern.length();

	int power=1;
	for(int i=0;i<patternLen;i++){
		power=((power%BASE)*31)%BASE;
	}

	//generate the hash for pattern to be searched
	int patternHash=0;
	for(int i=0;i<patternLen;i++){
		patternHash=(patternHash*31 + pattern[i])%BASE;
	}

	//keep generating hashCode for text and keep rolling over the lenght pieces of patternLen
	int hashCode=0;
	for(int i=0;i<textLen;i++){
		hashCode=(hashCode*31 + text[i])%BASE;

		if(i<patternLen-1) continue;//keep generating the hash
		if(i>=patternLen){
			hashCode=(hashCode- text[i-patternLen]*power)%BASE;
		}
		if(hashCode<0) hashCode+=BASE;

		if(hashCode==patternHash){ 
			if(text.substr(i-patternLen+1,patternLen)==pattern) ans.push_back(i-patternLen+1+1);
		}
	}
 
	return ans; 
}
