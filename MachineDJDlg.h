
// MachineDJDlg.h: 헤더 파일
//

#pragma once


// CMachineDJDlg 대화 상자
class CMachineDJDlg : public CDialogEx
{
// 생성입니다.
private:
	CBrush m_backBrush;
public:
	CMachineDJDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MACHINEDJ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 음료수 자판기 선언부
	afx_msg void OnBnClickedButton100();
	afx_msg void OnBnClickedButton500();
	afx_msg void OnBnClickedButton1000();
	afx_msg void OnBnClickedButtonReturn();
	afx_msg void OnBnClickedButtonCola();
	void DrawDrink(CPaintDC& dc, int bitmapID, int x, int y, int width, int height);
	HINSTANCE m_hInstance;
	afx_msg void OnBnClickedButtonButter();
	afx_msg void OnBnClickedButtonSoju();
	afx_msg void OnBnClickedButtonShrimp();
	afx_msg void OnBnClickedButtonMogu();
	afx_msg void OnBnClickedButtonBeer();
	CButton m_COLA;
	int m_Button_cola = 0;
	int m_Button_butter = 0;
	int m_Button_soju = 0;
	int m_Button_shrimp = 0;
	int m_Button_mogu = 0;
	int m_Button_beer = 0;
	int m_Button_conut = 0;

	// 음악 기능 선언부
	BOOL m_bPlaying;
	TCHAR m_szFullName[MAX_PATH];
	TCHAR m_szShortName[MAX_PATH];
	void ErrBox(DWORD dwErr);
	CListBox m_list_music;
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonPlay();
//	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton5000();
	afx_msg void OnBnClickedButton10000();
	afx_msg void OnBnClickedButtonOut();
};
