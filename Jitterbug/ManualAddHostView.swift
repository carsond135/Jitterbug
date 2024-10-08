//
// Copyright © 2021 osy. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

import SwiftUI

struct ManualAddHostView: View {
    @EnvironmentObject private var main: Main
    @State private var address: String = ""
    @Environment(\.presentationMode) private var presentationMode: Binding<PresentationMode>

    var body: some View {
        Form {
            List {
                #if canImport(UIKit)
                TextField("Host", text: $address)
                    .keyboardType(.asciiCapable)
                #else
                TextField("Host", text: $address)
                #endif
                Button {
                    presentationMode.wrappedValue.dismiss()
                    addHost(hostString: address)
                } label: {
                    Text("Add")
                }.disabled(address.isEmpty)
            }
        }.frame(minWidth: 250, minHeight: 150)
    }

    private func addHost(hostString: String) {
        main.backgroundTask(message: NSLocalizedString("Resolving...", comment: "ManualAddHostView")) {
            let host = CFHostCreateWithName(kCFAllocatorDefault, hostString as CFString).takeRetainedValue()
            CFHostStartInfoResolution(host, .addresses, nil)
            var success: DarwinBoolean = false

        }
    }
}
