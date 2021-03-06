﻿// Copyright 2012-2013 Alalf <alalf.iQLc_at_gmail.com>
//
// This file is part of SCFF-DirectShow-Filter(SCFF DSF).
//
// SCFF DSF is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SCFF DSF is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SCFF DSF.  If not, see <http://www.gnu.org/licenses/>.

/// @file SCFF.Common/Ext/DWMAPI.cs
/// @copydoc SCFF::Common::Ext::DWMAPI

namespace SCFF.Common.Ext {

using System.Runtime.InteropServices;

/// SCFFで利用するDWMAPI.dllのAPIをまとめたクラス
public class DWMAPI {
  //===================================================================
  // 定数
  //===================================================================

  /// AeroをOFFにするAction
  public const int DWM_EC_DISABLECOMPOSITION = 0;
  /// AeroをOnにするAction
  public const int DWM_EC_ENABLECOMPOSITION = 1;

  //===================================================================
  // API
  //===================================================================

  /// AeroがOnかどうか
  [DllImport("dwmapi.dll")]
  public static extern int DwmIsCompositionEnabled(out bool enabled);
  /// Aeroの状態を変更する
  [DllImport("dwmapi.dll")]
  public static extern int DwmEnableComposition(uint uCompositionAction);
}
}   // namespace SCFF.Common.Ext
