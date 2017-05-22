#pragma once
#include "afxwin.h"
#include "PreviewDlg.h"
#include "DIP_SystemDoc.h"
#include "DIP_SystemView.h"

// CStretchDlg �Ի���

class CStretchDlg : public CDialog
{
	// ��ǰ�������Ƶ�����
	enum PointType
	{
		PT_NULL,		// ���Ƶ�1
		PT_POINT_ONE,	// ���Ƶ�2
		PT_POINT_TWO	// ���Ƶ�3
	};

	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CStretchDlg)

public:
	CStatic			m_stiPrev;				// ͼ��Ԥ����
	float			m_dPsX1;				// ���Ƶ�1��x����
	float			m_dPsY1;				// ���Ƶ�1��y����
	float			m_dPsX2;				// ���Ƶ�2��x����
	float			m_dPsY2;				// ���Ƶ�2��y����
	bool			m_bInitialized;			// ���Ϊ��ʼ��
	int				m_nWidth;				// ͼ�����
	int				m_nHeight;				// ͼ��߶�
	int				m_nChannel;				// ͼ��ͨ��
	LONG			m_nRowLen;				// ͼ���п�
	LONG			m_nLength;				// ͼ�����ֽ�
	BYTE*			m_pSrc;					// ָ��ԭʼ����
	BYTE*			m_pBuf;					// ָ�򻺴�����

	// ��׼������������
	CStretchDlg(CWnd* pParent = NULL);
	virtual ~CStretchDlg();

	void Refresh();							// ˢ��Ԥ����

	CDIP_SystemDoc* GetDocument();			// ��ȡ��ĵ�
	CDIP_SystemView* GetActiveView();		// ��ȡ���ͼ
	virtual BOOL OnInitDialog();			// �Ի����ʼ��
	afx_msg void OnPaint();					// ���»��ƶԻ���
	afx_msg void OnEnChangePointoneX();		// �ı���Ƶ�1��x����ʱ����Ӧ����
	afx_msg void OnEnChangePointoneY();		// �ı���Ƶ�1��y����ʱ����Ӧ����
	afx_msg void OnEnChangePointtwoX();		// �ı���Ƶ�2��x����ʱ����Ӧ����
	afx_msg void OnEnChangePointtwoY();		// �ı���Ƶ�2��y����ʱ����Ӧ����
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
											// ����ƶ�ʱ��Ӧ�϶�����
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
											// ��������������Ӧ����
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
											// �ͷ�����������Ӧ����
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
											// ���������
	afx_msg void OnBnClickedSave();			// �����桱��ť��Ӧ����
	afx_msg void OnBnClickedOk();			// ��ȷ������ť��Ӧ����
	afx_msg void OnBnClickedCancel();		// ��ȡ������ť��Ӧ����

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
private:
	CPreviewDlg*	dlg;			// Ԥ���Ի���
	bool			m_bModify;		// ͼ���Ƿ��޸�
	bool			m_bIsDraging;	// �Ƿ������϶����Ƶ�
	int				m_nPointType;	// ��ǰ�������Ƶ�����

	// �Ի�������
	enum { IDD = IDD_DLG_STRETCH };
};
