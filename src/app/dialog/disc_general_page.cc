/*
 * InfraRecorder - CD/DVD burning software
 * Copyright (C) 2006-2012 Christian Kindahl
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdafx.hh"
#include "disc_general_page.hh"
#include "string_table.hh"
#include "lang_util.hh"
#include "settings.hh"
#include "trans_util.hh"
#include "core2.hh"

CDiscGeneralPage::CDiscGeneralPage(const TCHAR *szDiscLabel,ckmmc::Device &Device) :
    m_Device(Device)
{
    m_hIcon = NULL;

    lstrcpy(m_szDiscLabel,szDiscLabel);

    // Try to load translated string.
    if (g_LanguageSettings.m_pLngProcessor != NULL)
    {	
        // Make sure that there is a strings translation section.
        if (g_LanguageSettings.m_pLngProcessor->EnterSection(_T("strings")))
        {
            TCHAR *szStrValue;
            if (g_LanguageSettings.m_pLngProcessor->GetValuePtr(TITLE_GENERAL,szStrValue))
                SetTitle(szStrValue);
        }
    }
}

CDiscGeneralPage::~CDiscGeneralPage()
{
    if (m_hIcon != NULL)
        DestroyIcon(m_hIcon);
}

bool CDiscGeneralPage::Translate()
{
    if (g_LanguageSettings.m_pLngProcessor == NULL)
        return false;

    CLngProcessor *pLng = g_LanguageSettings.m_pLngProcessor;
    
    // Make sure that there is a device translation section.
    if (!pLng->EnterSection(_T("disc")))
        return false;

    // Translate.
    TCHAR *szStrValue;
    int iMaxStaticRight = 0;

    if (pLng->GetValuePtr(IDC_TYPELABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_TYPELABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_TYPELABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }
    if (pLng->GetValuePtr(IDC_BOOKLABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_BOOKLABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_BOOKLABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }
    if (pLng->GetValuePtr(IDC_REGIONLABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_REGIONLABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_REGIONLABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }
    if (pLng->GetValuePtr(IDC_LAYERLABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_LAYERLABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_LAYERLABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }
    if (pLng->GetValuePtr(IDC_TRACKLABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_TRACKLABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_TRACKLABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }
    if (pLng->GetValuePtr(IDC_SESSIONLABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_SESSIONLABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_SESSIONLABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }
    if (pLng->GetValuePtr(IDC_STATUSLABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_STATUSLABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_STATUSLABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }
    if (pLng->GetValuePtr(IDC_USEDSPACELABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_USEDSPACELABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_USEDSPACELABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }
    if (pLng->GetValuePtr(IDC_FREESPACELABELSTATIC,szStrValue))
    {
        SetDlgItemText(IDC_FREESPACELABELSTATIC,szStrValue);

        // Update the static width if necessary.
        int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_FREESPACELABELSTATIC,szStrValue);
        if (iStaticRight > iMaxStaticRight)
            iMaxStaticRight = iStaticRight;
    }

    // Make sure that the edit/combo controls are not in the way of the statics.
    if (iMaxStaticRight > 75)
    {
        UpdateEditPos(m_hWnd,IDC_TYPESTATIC,iMaxStaticRight);
        UpdateEditPos(m_hWnd,IDC_BOOKSTATIC,iMaxStaticRight);
        UpdateEditPos(m_hWnd,IDC_REGIONSTATIC,iMaxStaticRight);
        UpdateEditPos(m_hWnd,IDC_LAYERSTATIC,iMaxStaticRight);
        UpdateEditPos(m_hWnd,IDC_TRACKSTATIC,iMaxStaticRight);
        UpdateEditPos(m_hWnd,IDC_SESSIONSTATIC,iMaxStaticRight);
        UpdateEditPos(m_hWnd,IDC_STATUSSTATIC,iMaxStaticRight);
        UpdateEditPos(m_hWnd,IDC_USEDSPACESTATIC,iMaxStaticRight);
        UpdateEditPos(m_hWnd,IDC_FREESPACESTATIC,iMaxStaticRight);
    }

    return true;
}

void CDiscGeneralPage::DisplayDiscType(ckmmc::Device::Profile Profile)
{
    switch (Profile)
    {
        case ckmmc::Device::ckPROFILE_CDROM:
            SetDlgItemText(IDC_TYPESTATIC,_T("CD-ROM")); break;
        case ckmmc::Device::ckPROFILE_CDR:
            SetDlgItemText(IDC_TYPESTATIC,_T("CD-R")); break;
        case ckmmc::Device::ckPROFILE_CDRW:
            SetDlgItemText(IDC_TYPESTATIC,_T("CD-RW")); break;
        case ckmmc::Device::ckPROFILE_DVDROM:
            SetDlgItemText(IDC_TYPESTATIC,_T("DVD-ROM")); break;
        case ckmmc::Device::ckPROFILE_DVDMINUSR_SEQ:
            SetDlgItemText(IDC_TYPESTATIC,_T("DVD-R")); break;
        case ckmmc::Device::ckPROFILE_DVDRAM:
            SetDlgItemText(IDC_TYPESTATIC,_T("DVD-RAM")); break;
        case ckmmc::Device::ckPROFILE_DVDMINUSRW_RESTOV:
            {
                TCHAR szBuffer[64];
                lstrcpy(szBuffer,_T("DVD-RW "));
                lstrcat(szBuffer,lngGetString(DISC_RESTRICTEDOVERWRITE));

                SetDlgItemText(IDC_TYPESTATIC,szBuffer);
            }
            break;
        case ckmmc::Device::ckPROFILE_DVDMINUSRW_SEQ:
            {
                TCHAR szBuffer[64];
                lstrcpy(szBuffer,_T("DVD-RW "));
                lstrcat(szBuffer,lngGetString(DISC_SEQUENTIAL));

                SetDlgItemText(IDC_TYPESTATIC,szBuffer);
            }
            break;
        case ckmmc::Device::ckPROFILE_DVDMINUSR_DL_SEQ:
        case ckmmc::Device::ckPROFILE_DVDMINUSR_DL_JUMP:
            SetDlgItemText(IDC_TYPESTATIC,_T("DVD-R DL")); break;
        case ckmmc::Device::ckPROFILE_DVDPLUSRW:
            SetDlgItemText(IDC_TYPESTATIC,_T("DVD+RW")); break;
        case ckmmc::Device::ckPROFILE_DVDPLUSR:
            SetDlgItemText(IDC_TYPESTATIC,_T("DVD+R")); break;
        case ckmmc::Device::ckPROFILE_DVDPLUSRW_DL:
            SetDlgItemText(IDC_TYPESTATIC,_T("DVD+RW DL")); break;
        case ckmmc::Device::ckPROFILE_DVDPLUSR_DL:
            SetDlgItemText(IDC_TYPESTATIC,_T("DVD+R DL")); break;
        case ckmmc::Device::ckPROFILE_BDROM:
            SetDlgItemText(IDC_TYPESTATIC,_T("BD-ROM")); break;
        case ckmmc::Device::ckPROFILE_BDR_SRM:
            SetDlgItemText(IDC_TYPESTATIC,_T("BD-R SRM")); break;
        case ckmmc::Device::ckPROFILE_BDR_RRM:
            SetDlgItemText(IDC_TYPESTATIC,_T("BD-R RRM")); break;
        case ckmmc::Device::ckPROFILE_BDRE:
            SetDlgItemText(IDC_TYPESTATIC,_T("BD-RE")); break;
        case ckmmc::Device::ckPROFILE_HDDVDROM:
            SetDlgItemText(IDC_TYPESTATIC,_T("HD DVD-ROM")); break;
        case ckmmc::Device::ckPROFILE_HDDVDR:
            SetDlgItemText(IDC_TYPESTATIC,_T("HD DVD-R")); break;
        case ckmmc::Device::ckPROFILE_HDDVDRAM:
            SetDlgItemText(IDC_TYPESTATIC,_T("HD DVD-RAM")); break;
        default:
            SetDlgItemText(IDC_TYPESTATIC,lngGetString(DISC_UNKNOWN)); break;
    }
}

void CDiscGeneralPage::DisplayBookType(unsigned char ucBookType,unsigned char ucBookRev)
{
    TCHAR szBookType[64];

    switch (ucBookType)
    {
        case 0:
            lsprintf(szBookType,_T("DVD-ROM (%s %d)"),lngGetString(DISC_REVISION),ucBookRev); break;
        case 1:
            lsprintf(szBookType,_T("DVD-RAM (%s %d)"),lngGetString(DISC_REVISION),ucBookRev); break;
        case 2:
            lsprintf(szBookType,_T("DVD-R (%s %d)"),lngGetString(DISC_REVISION),ucBookRev); break;
        case 3:
            lsprintf(szBookType,_T("DVD-RW (%s %d)"),lngGetString(DISC_REVISION),ucBookRev); break;
        case 9:
            lsprintf(szBookType,_T("DVD+RW (%s %d)"),lngGetString(DISC_REVISION),ucBookRev); break;
        case 10:
            lsprintf(szBookType,_T("DVD+R (%s %d)"),lngGetString(DISC_REVISION),ucBookRev); break;
        case 14:
            lsprintf(szBookType,_T("DVD+R DL (%s %d)"),lngGetString(DISC_REVISION),ucBookRev); break;
        default:
            lsprintf(szBookType,lngGetString(DISC_UNKNOWN)); break;
    }

    SetDlgItemText(IDC_BOOKSTATIC,szBookType);
}

void CDiscGeneralPage::DisplayStatus(CCore2DiscInfo *pDiscInfo)
{
    const TCHAR *szDiscStatus = _T("");
    const TCHAR *szSessionStatus = _T("");

    switch (pDiscInfo->m_ucDiscStatus)
    {
        case CCore2DiscInfo::DS_EMTPY:
            szDiscStatus = lngGetString(DISC_BLANK); break;
        case CCore2DiscInfo::DS_INCOMPLETE:
            szDiscStatus = lngGetString(DISC_INCOMPLETE); break;
        case CCore2DiscInfo::DS_FINALIZED:
            szDiscStatus = lngGetString(DISC_FIXATED); break;
        case CCore2DiscInfo::DS_RANDOMACCESS:
            szDiscStatus = lngGetString(DISC_RANDOMACCESS); break;
    }

    switch (pDiscInfo->m_ucLastSessStatus)
    {
        case CCore2DiscInfo::LSS_EMTPY:
            szSessionStatus = lngGetString(DISC_EMPTY); break;
        case CCore2DiscInfo::LSS_INCOMPLETE:
            szSessionStatus = lngGetString(DISC_INCOMPLETE); break;
        case CCore2DiscInfo::LSS_RESERVED:
            szSessionStatus = lngGetString(DISC_RESERVED); break;
        case CCore2DiscInfo::LSS_COMPLETE:
            szSessionStatus = lngGetString(DISC_COMPLETE); break;
    }

    TCHAR szStatus[256];
    lsprintf(szStatus,lngGetString(DISC_STATUS),szDiscStatus,szSessionStatus,
        pDiscInfo->m_ucFlags & CCore2DiscInfo::FLAG_ERASABLE ? _T("") : lngGetString(DISC_NOT));

    SetDlgItemText(IDC_STATUSSTATIC,szStatus);
}

LRESULT CDiscGeneralPage::OnInitDialog(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
    // Create the icon.
    HINSTANCE hInstance = LoadLibrary(_T("shell32.dll"));
        m_hIcon = (HICON)LoadImage(hInstance,MAKEINTRESOURCE(12),IMAGE_ICON,GetSystemMetrics(SM_CXICON),GetSystemMetrics(SM_CYICON),LR_DEFAULTCOLOR);
    FreeLibrary(hInstance);

    SendMessage(GetDlgItem(IDC_ICONSTATIC),STM_SETICON,(WPARAM)m_hIcon,0L);

    // Display the information.
    SetDlgItemText(IDC_NAMESTATIC,m_szDiscLabel);

    CCore2Info Info;

    ckmmc::Device::Profile Profile = m_Device.profile();
    DisplayDiscType(Profile);

    // Extra DVD information.
    unsigned int uiNumLayers = 0;
    TCHAR szSmallBuffer[64];

    if (Profile == ckmmc::Device::ckPROFILE_DVDROM || Profile == ckmmc::Device::ckPROFILE_DVDMINUSR_SEQ || Profile == ckmmc::Device::ckPROFILE_DVDRAM ||
        Profile == ckmmc::Device::ckPROFILE_DVDMINUSRW_RESTOV || Profile == ckmmc::Device::ckPROFILE_DVDMINUSRW_SEQ || Profile == ckmmc::Device::ckPROFILE_DVDMINUSR_DL_SEQ ||
        Profile == ckmmc::Device::ckPROFILE_DVDMINUSR_DL_JUMP || Profile == ckmmc::Device::ckPROFILE_DVDPLUSRW || Profile == ckmmc::Device::ckPROFILE_DVDPLUSR ||
        Profile == ckmmc::Device::ckPROFILE_DVDPLUSRW_DL || Profile == ckmmc::Device::ckPROFILE_DVDPLUSR_DL)
    {
        // Book type.
        CCore2PhysFmtInfo PhysInfo;
        if (Info.ReadPhysFmtInfo(m_Device,&PhysInfo))
            DisplayBookType(PhysInfo.m_ucDiscCategory,PhysInfo.m_ucPartVersion);
        else
            SetDlgItemText(IDC_BOOKSTATIC,lngGetString(DISC_UNKNOWN));

        // Region.
        unsigned char ucRegion = 0;

        if (Info.GetDiscDVDRegion(m_Device,ucRegion))
        {
            if (ucRegion == 0)
                SetDlgItemText(IDC_REGIONSTATIC,lngGetString(DISC_NOREGION));
            else
            {
                lsprintf(szSmallBuffer,_T("%d"),(int)ucRegion);
                SetDlgItemText(IDC_REGIONSTATIC,szSmallBuffer);
            }
        }
        else
            SetDlgItemText(IDC_REGIONSTATIC,lngGetString(DISC_UNKNOWN));

        // Layers
        lsprintf(szSmallBuffer,_T("%d"),uiNumLayers);
        SetDlgItemText(IDC_LAYERSTATIC,szSmallBuffer);
    }
    else
    {
        // Book type.
        SetDlgItemText(IDC_BOOKSTATIC,lngGetString(DISC_UNKNOWN));
        ::EnableWindow(GetDlgItem(IDC_BOOKSTATIC),false);
        ::EnableWindow(GetDlgItem(IDC_BOOKLABELSTATIC),false);

        // Region.
        SetDlgItemText(IDC_REGIONSTATIC,lngGetString(DISC_UNKNOWN));
        ::EnableWindow(GetDlgItem(IDC_REGIONSTATIC),false);
        ::EnableWindow(GetDlgItem(IDC_REGIONLABELSTATIC),false);

        // Layers.
        SetDlgItemText(IDC_LAYERSTATIC,lngGetString(DISC_UNKNOWN));
        ::EnableWindow(GetDlgItem(IDC_LAYERSTATIC),false);
        ::EnableWindow(GetDlgItem(IDC_LAYERLABELSTATIC),false);
    }

    CCore2DiscInfo DiscInfo;
    if (Info.ReadDiscInformation(m_Device,&DiscInfo))
    {
        // Tracks.
        lsprintf(szSmallBuffer,_T("%d"),DiscInfo.m_usLastSessLstTrack - (DiscInfo.m_usLastSessFstTrack - 1));
        SetDlgItemText(IDC_TRACKSTATIC,szSmallBuffer);

        // Sessions.
        lsprintf(szSmallBuffer,_T("%d"),DiscInfo.m_usNumSessions);
        SetDlgItemText(IDC_SESSIONSTATIC,szSmallBuffer);

        // Status.
        DisplayStatus(&DiscInfo);

        // Space.
        unsigned __int64 uiUsedSize = 0;
        unsigned __int64 uiFreeSize = 0;
        if (Info.GetTotalDiscCapacity(m_Device,uiUsedSize,uiFreeSize))
        {
            FormatBytes(szSmallBuffer,uiUsedSize);
            lsprintf(szSmallBuffer + lstrlen(szSmallBuffer),_T(" (%I64d Bytes)"),uiUsedSize);
            SetDlgItemText(IDC_USEDSPACESTATIC,szSmallBuffer);

            FormatBytes(szSmallBuffer,uiFreeSize);
            lsprintf(szSmallBuffer + lstrlen(szSmallBuffer),_T(" (%I64d Bytes)"),uiFreeSize);
            SetDlgItemText(IDC_FREESPACESTATIC,szSmallBuffer);
        }
        else
        {
            // Used space.
            SetDlgItemText(IDC_USEDSPACESTATIC,lngGetString(DISC_UNKNOWN));
            ::EnableWindow(GetDlgItem(IDC_USEDSPACESTATIC),false);
            ::EnableWindow(GetDlgItem(IDC_USEDSPACELABELSTATIC),false);

            // Free space.
            SetDlgItemText(IDC_FREESPACESTATIC,lngGetString(DISC_UNKNOWN));
            ::EnableWindow(GetDlgItem(IDC_FREESPACESTATIC),false);
            ::EnableWindow(GetDlgItem(IDC_FREESPACELABELSTATIC),false);
        }
    }
    else
    {
        // Tracks.
        SetDlgItemText(IDC_TRACKSTATIC,lngGetString(DISC_UNKNOWN));
        ::EnableWindow(GetDlgItem(IDC_TRACKSTATIC),false);
        ::EnableWindow(GetDlgItem(IDC_TRACKLABELSTATIC),false);

        // Sessions.
        SetDlgItemText(IDC_SESSIONSTATIC,lngGetString(DISC_UNKNOWN));
        ::EnableWindow(GetDlgItem(IDC_SESSIONSTATIC),false);
        ::EnableWindow(GetDlgItem(IDC_SESSIONLABELSTATIC),false);

        // Status.
        SetDlgItemText(IDC_STATUSSTATIC,lngGetString(DISC_UNKNOWN));
        ::EnableWindow(GetDlgItem(IDC_STATUSSTATIC),false);
        ::EnableWindow(GetDlgItem(IDC_STATUSLABELSTATIC),false);

        // Used space.
        SetDlgItemText(IDC_USEDSPACESTATIC,lngGetString(DISC_UNKNOWN));
        ::EnableWindow(GetDlgItem(IDC_USEDSPACESTATIC),false);
        ::EnableWindow(GetDlgItem(IDC_USEDSPACELABELSTATIC),false);

        // Free space.
        SetDlgItemText(IDC_FREESPACESTATIC,lngGetString(DISC_UNKNOWN));
        ::EnableWindow(GetDlgItem(IDC_FREESPACESTATIC),false);
        ::EnableWindow(GetDlgItem(IDC_FREESPACELABELSTATIC),false);
    }

    // Translate the window.
    Translate();

    return TRUE;
}
