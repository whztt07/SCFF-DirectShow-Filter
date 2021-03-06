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

/// @file scff_imaging/request.h
/// scff_imaging::Requestの宣言

#ifndef SCFF_DSF_SCFF_IMAGING_REQUEST_H_
#define SCFF_DSF_SCFF_IMAGING_REQUEST_H_

#include "scff_imaging/engine.h"

namespace scff_imaging {

/// エンジンに対するリクエストをカプセル化したクラス
class Request {
 public:
  /// デストラクタ
  virtual ~Request() {
    // nop
  }
  /// ダブルディスパッチ用
  virtual void SendTo(Engine *engine) const = 0;
 protected:
  /// コンストラクタ
  Request() {
    // nop
  }
};

/// リクエスト: ResetLayout
class ResetLayoutRequest : public Request {
 public:
  /// コンストラクタ
  ResetLayoutRequest() : Request() {
    // このリクエストは特に情報を必要としない
  }
  /// デストラクタ
  ~ResetLayoutRequest() {
    // nop
  }
  /// ダブルディスパッチ用
  void SendTo(Engine *engine) const {
    engine->ResetLayout();
  }
};

/// リクエスト: SetLayout
class SetLayoutRequest : public Request {
 public:
  /// コンストラクタ
  SetLayoutRequest(
      int element_count,
      const LayoutParameter (&parameters)[kMaxProcessorSize])
      : Request(),
        element_count_(element_count) {
    // 配列の初期化
    for (int i = 0; i < kMaxProcessorSize; i++) {
      parameters_[i] = parameters[i];
    }
  }
  /// デストラクタ
  ~SetLayoutRequest() {
    // nop
  }
  /// ダブルディスパッチ用
  void SendTo(Engine *engine) const {
    engine->SetLayoutParameters(element_count_, parameters_);
    if (element_count_ == 1) {
      engine->SetNativeLayout();
    } else {
      engine->SetComplexLayout();
    }
  }

 private:
  /// レイアウト要素数
  const int element_count_;

  /// レイアウトパラメータ
  LayoutParameter parameters_[kMaxProcessorSize];
};

}   // namespace scff_imaging

#endif  // SCFF_DSF_SCFF_IMAGING_REQUEST_H_
