#ifndef MYVECTOR3_H_
#define MYVECTOR3_H_

class cParticle;

class cMyVector3 {
	
	public:
		
		cMyVector3 (); // +
		cMyVector3 (double x_, double y_, double z_); // +
		
		cMyVector3 (const double *array, int starter = 0); // +
		   
		~cMyVector3 (); // not realised
		
		double operator () (int i) const; // +
		
		//inline Double_t operator [] (int) const; // not realised
		
		//Function for add numbers

		double x ()  const { return fX; } // +
		double y ()  const { return fY; } // +
		double z ()  const { return fZ; } // +
		double X ()  const { return fX; } // +
		double Y ()  const { return fY; } // +
		double Z ()  const { return fZ; } // +
		double Px () const { return fX; } // +
		double Py () const { return fY; } // +
		double Pz () const { return fZ; } // +
		
		 void SetX (double);// +
		 void SetY (double);// +
		 void SetZ (double);// +
		 void SetXYZ (double x_, double y_, double z_); // +

// *** funny good things	
		inline void GetXYZ (double *carray, int starter = 0) const; // +
   
    inline double  Dot (const cMyVector3 &) const;
// *** Not realised, do if you want  
/*
		void SetPtEtaPhi (Double_t pt, Double_t eta, Double_t phi);
		void SetPtThetaPhi (Double_t pt, Double_t theta, Double_t phi);
		
		Double_t Phi () const;
		Double_t Theta () const;
		
		inline Double_t CosTheta () const;
		inline Double_t Mag2 () const;
		
		Double_t Mag () const;
		void SetPhi (Double_t);
		
		void SetTheta (Double_t);
		inline void SetMag (Double_t);
		
		inline Double_t Perp2 () const;
		inline Double_t Pt () const;
		
		Double_t Perp () const;
		inline void SetPerp (Double_t);
*/
// *** end
	
		 cMyVector3 & operator = (const cMyVector3 &); // +
	  
		inline bool operator == (const cMyVector3 &) const; // +
                                                          
		inline bool operator != (const cMyVector3 &) const; // +
		
		inline cMyVector3 & operator += (const cMyVector3 &); // +
		
		inline cMyVector3 & operator -= (const cMyVector3 &); // +
		
		inline cMyVector3 operator - () const; // +
		
		inline cMyVector3 & operator *= (double); // +
   
	private:
		
		double fX, fY, fZ;
	
};





#endif
