#pragma once


struct stEMUV
{
	float m_fU;
	float m_fV;

	stEMUV()
	{m_fU = 0.0f; m_fV=0.0f;}
	~stEMUV(){};
};

struct stEMIndex
{
	unsigned short m_nV[3];

	stEMIndex(){ m_nV[0] = 0; m_nV[1] = 0; m_nV[2] = 0; }
	~stEMIndex(){};
};

struct stEM3DBoundingBox
{
/*
 (-+) LT ---------- RT(++)
	    |	  	   |
	    |		   |
 (--) LB ---------- RB(+-)
*/
	//����
	stEMVec3 stFLT;		
	stEMVec3 stFLB;
	stEMVec3 stFRT;
	stEMVec3 stFRB;

	//����
	stEMVec3 stBLT;		
	stEMVec3 stBLB;
	stEMVec3 stBRT;
	stEMVec3 stBRB;

// 
// 	float fRadius;					//!< ������
// 	stEMVec3 stCenterPosVec3;		//!< �� �� box�� �߽� offset��ġ�� ����Ǿ��� ���� �����ġ
// 
// 	bool operator==(const stEMBoundingBox &stBBox) const;
};


typedef std::vector<stEMVec2>	stlEMVec2List;
typedef std::map<int, stlEMVec2List> stlMapData;
typedef std::vector<b2Body*> stlpb2Body;


/*
	[ ASE���� ���ǻ���]
		1. ???.map���� SetSize()�ϰԵǸ� �׸�������� ���������� �浹���� ???.map�� ���������ʾƿ�
		2. ȸ���� �ص� ���������Դϴ�. �浹������ ���� ???.map�� ȸ������ �ʽ��ϴ� �����ϼ���
*/
class CEMAseImport
{
public:
	char			m_Data[1024];
	stdEMString 	m_cImageName;
	FILE*			m_pFp;

	stEM3DBoundingBox	m_st3DBoundingBox;
public:
	int				m_nVertexs;				//!< *MESH_NUMVERTEX
	int				m_nVertexIndexs;		//!< *MESH_NUMFACES

	int				m_nUVs;					//!< *MESH_NUMTVERTEX
	int				m_nUVIndexs;			//!< *MESH_NUMTVFACES
	int				m_nRenderIndexs;		//!< ���� glDrawElements���� ����� Face ��

public:
	stEMVec3*		m_pVertex;				//!< *MESH_VERTEX_LIST
	stEMIndex*		m_pVertexIndex;			//!< *MESH_FACE_LIST

	stEMUV*			m_pUV;					//!< *MESH_TVERTLIST
	stEMIndex*		m_pUVIndex;				//!< *MESH_TFACELIST

public:
	stEMVec3*		m_pSortVertex;			//!< ���� ����Ҷ� ����� ���ؽ�
	unsigned short*	m_pSortIndex;			//!< ���� ����Ҷ� ����� �ε���
	stEMUV*			m_pSortUV;				//!< ���� ����Ҷ� ����� uv
	
public:
	int				m_nTotalCollisions;		//!< 
	stlMapData		m_stlMapInfo;			//!< ???.map ������ �ε� �ؼ� �����ϴ� ���Դϴ�.
	stlpb2Body		m_pBodys;				//!< ASE�ε��ϸ鼭 ���� ����
public:
	bool			m_bMapDataLoad;			//!< ???.map �� �ҷ��Դ��� �ƴ����� �����մϴ�
	CRootScene*		m_pCurScene;

public:
	stdEMString		m_stdAseFileName;		//!< ase  ���� �̸�
	stdEMString		m_stdMapName;			//!< �浹 ó�� ���� ???.map

public:
	//CEMAse();
	CEMAseImport(stdEMString stAseName, stdEMString stdMapFileName);
	~CEMAseImport();

public:
	void		ReleaseMemory();
	bool		ImportAse(stdEMString str, stdEMString stdMapFileName);
	bool		ImportMap(stdEMString str);
	bool		FindString(stdEMString str, stdEMString Dest = "");

	bool		CmpStr(char* str)			{ return (!strcmp(m_Data, str)) ? true : false;	}
	stEMVec3	GetVector3(FILE *fp)		{ static stEMVec3	v;	fscanf(fp, "%f %f %f", &v.m_fX, &v.m_fZ, &v.m_fY);	v.m_fZ*=-1.0f;		return v;	}
	stEMUV		GetUV2(FILE *fp)			{ static stEMUV		v;	fscanf(fp, "%f %f", &v.m_fU, &v.m_fV);	/*v.m_fV = 1.0f - v.m_fV;	*/	return v;	}
	char*		GetString(FILE* fp)			{ static char str[1024];	fscanf(fp, "%s", &str); return str; }
	float		GetFloat(FILE* fp)			{ static float n; fscanf(fp, "%f", &n); return n; }
	int			GetInt(FILE* fp)			{ static int n; fscanf(fp, "%d", &n); return n;}

	stEMIndex	GetVertexIndex(FILE* fp)	{ static stEMIndex	n; fscanf(fp, ":\tA:\t%d B:\t%d C:\t%d", &n.m_nV[0], &n.m_nV[1], &n.m_nV[2]);	return n; }
	stEMIndex	GetTVertexIndex(FILE* fp)	{ static stEMIndex	n; fscanf(fp, "%d %d %d", &n.m_nV[0], &n.m_nV[1], &n.m_nV[2]); return n; }

	bool		VertexSort();
	void		CalcMinMax();				//!< ���ؽ� �������� �ּ� �ִ� ������ ������ BoundingBox�� ����ؼ� �ִ´�.
};

class CEMAse :public CEMPlane
{
private:
	CEMAseImport*	m_pAse;
	CRootScene*		m_pCurScene;

public:
	stEMVec3		m_stSizeVec3;			//!< ASE���� ���Ǿ��� ������ �Դϴ�.

public:
	CEMAse(CRootScene* pScene, stdEMString stFileName, stdEMString stMapFileName = "");

	~CEMAse()
	{

	};

public:
	CEMAseImport* GetAseInfoPt()		{return m_pAse;}

public:
	virtual void Update(float dt);
	virtual void Render();

	void SetSize(float fX=1.0f, float fY=1.0f, float fZ=1.0f);
	void SetSize(stEMVec3 stSizeVec3);
	//virtual stEMVec3 GetSize()	{return m_stSizeVec3;}

	virtual const stdEMString GetClassName() { return "CEMAse"; }

};