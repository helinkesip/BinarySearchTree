
#include <iostream>

struct BSTdugum {
	int veri;
	BSTdugum* sol;
	BSTdugum* sag;
};

BSTdugum* root = NULL;


BSTdugum* dugumOlustur(int veri) {
	BSTdugum* yeniDugum = (BSTdugum*)malloc(sizeof(BSTdugum));
	yeniDugum->veri = veri;
	yeniDugum->sol= NULL;
	yeniDugum->sag = NULL;

	return yeniDugum;
}



BSTdugum* dugumEkle(BSTdugum* root, int veri) {
	if (root == NULL) {
		root = dugumOlustur(veri);
	}
	else {
		if (root->veri > veri) {
			root-> sol = dugumEkle(root->sol, veri);
		}
		else if (root->veri < veri) {
			root->sag = dugumEkle(root->sag, veri);
		}
	}
	return root;
}



void dugumAra(BSTdugum* root, int arananveri) {
	if (root->veri == arananveri) {
		printf("\n%d verisi kokte bulundu",arananveri);
	}
	else {
		if (root->veri < arananveri) {
			dugumAra(root->sag, arananveri);
		}
		else if (root->veri > arananveri) {
			dugumAra(root->sol, arananveri);
		}
	}
}


void inorderDolas(BSTdugum* root) { //sol kok sag
	if (root != NULL) {
		inorderDolas(root->sol);
		printf("%d - ", root->veri);
		inorderDolas(root->sag);

	}

}


void preorderDolas(BSTdugum* root) { //kok sol sağ
	printf("%d - ", root->veri);
	preorderDolas(root->sol);
	preorderDolas(root->sag);

}


void postorderDolas(BSTdugum* root) { //sol sağ kök 
	postorderDolas(root->sol);
	postorderDolas, (root->sag);
	printf("%d - ", root->veri);
	
}


BSTdugum* dugumSil(BSTdugum* root, int silinenveri) {
	if (root == NULL) return NULL;

	if (root->veri < silinenveri) {
		root->sol = dugumSil(root, silinenveri);
	}
	else if(root->veri > silinenveri) {
		root->sag = dugumSil(root, silinenveri);
	}
	else {

	//üç durum kontrolü 
		// 1) Yaprak mı?
		// 2) Tek çocuklu mu?
		// 3) İki çocuklu mu?

		if (root->sag == NULL && root->sol == NULL) {
			free(root);
			return NULL;	
		}
		else if(root->sol == NULL && root->sag != NULL) {
			BSTdugum* temp = root->sag;
			free(root);
			return temp;

		}
		else if (root->sol != NULL && root->sag == NULL) {
			BSTdugum* temp = root->sol;
			free(root);
			return temp;

		}

	}	

}



int main()
{
	BSTdugum* root = NULL;
	root = dugumEkle(root, 2);
	root = dugumEkle(root, 5);
	root = dugumEkle(root, 89);
	root = dugumEkle(root, 32);
	root = dugumEkle(root, 256);
	root = dugumEkle(root, 0);
	root = dugumEkle(root, 4);
	root = dugumEkle(root, 3);

	inorderDolas(root);
	dugumAra(root,32);
	



}

