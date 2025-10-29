set shell=\"$PROGRAMFILES\Git\bin\sh.exe\"
set shellcmdflag=-c

set scrolloff=5

let mapleader=" "

" Reset the ime state when leaving insert mode
inoremap <ESC> <ESC>:set iminsert=0<CR>

noremap <C-Up> gk
noremap <C-Down> gj
noremap <S-Up> <C-y>
noremap <S-Down> <C-e>

nmap <C-P> :<CR>
nmap <C-N> :<CR>

nmap l "*
xmap l "*

#ifdef RESHARPER
nmap <C-O> :vsc ReSharper.ReSharper_NavigateBackward<CR>
nmap <C-I> :vsc ReSharper.ReSharper_NavigateForward<CR>
#else
nmap <C-O> :vsc View.NavigateBackward<CR>
nmap <C-I> :vsc View.NavigateForward<CR>
#endif
nmap <C-P> <C-O><C-I>

nmap gh :vsc Edit.QuickInfo<CR>
#ifdef RESHARPER
nmap gl :vsc ReSharper.ReSharper_QuickDoc<CR>
nmap ga :vsc ReSharper.ReSharper_ShowUsages<CR>
nmap gy :vsc ReSharper.ReSharper_GotoTypeDeclaration<CR>
nmap gi :vsc ReSharper.ReSharper_GoToImplementations<CR>
nmap gb :vsc ReSharper.ReSharper_GotoBase<CR>
nmap go :vsc ReSharper.ReSharper_GotoInheritors<CR>
nmap gcc :vsc ReSharper.ReSharper_LineComment<CR>
xmap gcc :vsc ReSharper.ReSharper_LineComment<CR>
#else
nmap ga :vsc Edit.FindAllReferences<CR>
nmap gy :vsc Edit.GotoTypeDefinition<CR>
nmap gi :vsc Edit.GoToImplementation<CR>
nmap gb :vsc Edit.GoToBase<CR>
nmap gcc :vsc Edit.ToggleLineComment<CR>
xmap gcc :vsc Edit.ToggleLineComment<CR>
#endif

#ifdef RESHARPER
nmap <A-Up> :vsc ReSharper.ReSharper_ResultListGoToPrevLocation<CR>
nmap <A-Down> :vsc ReSharper.ReSharper_ResultListGoToNextLocation<CR>
nmap <C-Space><C-a> :vsc ReSharper.ReSharper_GoToText<CR>
nmap <C-Space>a "*yiw:vsc ReSharper.ReSharper_GoToText<CR>
xmap <C-Space><C-a> :vsc ReSharper.ReSharper_GoToText<CR>
nmap <C-Space><C-r> :vsc ReSharper.ReSharper_GoToSymbol<CR>
nmap <C-Space>r "*yiw:vsc ReSharper.ReSharper_GoToSymbol<CR>
xmap <C-Space><C-r> :vsc ReSharper.ReSharper_GoToSymbol<CR>
nmap <C-Space><C-s> :vsc ReSharper.ReSharper_GoToType<CR>
nmap <C-Space>s "*yiw:vsc ReSharper.ReSharper_GoToType<CR>
xmap <C-Space><C-s> :vsc ReSharper.ReSharper_GoToType<CR>
nmap <C-Space><C-t> :vsc ReSharper.ReSharper_GoToFileMember<CR>
xmap <C-Space><C-t> :vsc ReSharper.ReSharper_GoToFileMember<CR>
nmap <C-Space><C-g> :vsc ReSharper.ReSharper_GotoRecentFiles<CR>
xmap <C-Space><C-g> :vsc ReSharper.ReSharper_GotoRecentFiles<CR>
nmap <C-Space><C-c> :vsc ReSharper.ReSharper_GotoContainingDeclaration<CR>
#else
nmap <C-Space><C-a> :vsc Edit.GoToText<CR>
nmap <C-Space><C-r> :vsc Edit.GoToSymbol<CR>
nmap <C-Space><C-s> :vsc Edit.GoToType<CR>
nmap <C-Space><C-t> :vsc Edit.GoToMember<CR>
nmap <C-Space><C-g> :vsc Edit.GoToFile<CR>
#endif

nmap <BS> :vsc Tools.InvokePeasyMotion<CR>
nmap <A-BS> :vsc Tools.InvokePeasyMotionJumpToLineBegining<CR>
nmap <S-BS> :vsc Tools.InvokePeasyMotionTextSelect<CR>
nmap <C-BS><C-n> :vsc Tools.InvokePeasyMotionLineJumpToWordBegining<CR>
nmap <C-BS><C-o> :vsc Tools.InvokePeasyMotionLineJumpToWordEnding<CR>
nmap <C-BS><C-e> :vsc Tools.InvokePeasyMotionOneCharJump<CR>
nmap <C-BS><C-i> :vsc Tools.InvokePeasyMotionTwoCharJump<CR>

nmap <leader>rr :vsc Edit.ToggleOutliningExpansion<CR>

" Jumps aren't registered in ReSharper's history
" nmap <leader><Tab> :vsc Window.NextDocumentWindowNav<CR>

#ifdef RESHARPER
nmap <leader>ff :vsc ReSharper.ReSharper_GoToFileNearby<CR>
#endif
nmap <leader>fo :vsc File.OpenFile<CR>
nmap <leader>fs :w<CR>:echo "File saved"<CR>
nmap <leader>fS :wa<CR>:echo "All files saved"<CR>
nmap <leader>fq :x<CR>
nmap <leader>fy :vsc File.CopyFullPath<CR>:echo "File path copied"<CR>
nmap <leader>ft :vsc EditorContextMenus.CodeWindow.ToggleHeaderCodeFile<CR>

#ifdef RESHARPER
nmap <leader>ii :vsc ReSharper.ReSharper_InspectThis<CR>
nmap <leader>ic :vsc ReSharper.ReSharper_CallHierarchyShowIncomingCalls<CR>
nmap <leader>iC :vsc ReSharper.ReSharper_CallHierarchyShowOutgoingCalls<CR>
nmap <leader>iv :vsc ReSharper.ReSharper_DfaReachingDefinitionsUp<CR>
nmap <leader>iV :vsc ReSharper.ReSharper_DfaReachingDefinitionsDown<CR>
nmap <leader>il :vsc ReSharper.ReSharper_ShowIlViewerWindow<CR>
nmap <leader>iu :vsc ReSharper.ReSharper_FindUsages<CR>
#else
nmap <leader>ic :vsc EditorContextMenus.CodeWindow.ViewCallHierarchy<CR>
#endif

#ifdef RESHARPER
nmap <leader>ee :vsc ReSharper_AltEnter<CR>
xmap <leader>ee :vsc ReSharper_AltEnter<CR>
nmap <leader>er :vsc ReSharper.ReSharper_RefactorThis<CR>
xmap <leader>er :vsc ReSharper.ReSharper_RefactorThis<CR>
nmap <leader>ef :vsc ReSharper.ReSharper_ReformatCode<CR>
xmap <leader>ef :vsc ReSharper.ReSharper_ReformatCode<CR>
nmap <leader>ec :vsc ReSharper.ReSharper_Rename<CR>
xmap <leader>ec :vsc ReSharper.ReSharper_Rename<CR>
xmap <leader>es :vsc ReSharper.ReSharper_SurroundWith<CR>
#else
nmap <leader>er :vsc EditorContextMenus.CodeWindow.QuickActionsForPosition<CR>
xmap <leader>er :vsc EditorContextMenus.CodeWindow.QuickActionsForPosition<CR>
nmap <leader>ef :vsc Edit.FormatDocument<CR>
xmap <leader>ef :vsc Edit.FormatSelection<CR>
nmap <leader>ec :vsc Refactor.Rename<CR>
#endif

#ifdef RESHARPER
nmap <leader>hh :vsc ReSharper.ReSharper_GotoRecentEdits<CR>
#endif
nmap <leader>ho :vsc Edit.GoToLastEditLocation<CR>

#ifdef RESHARPER
nmap <leader>pe :vsc ReSharper.ReSharper_GotoNextErrorInSolution<CR>
nmap <leader>pi :vsc ReSharper.ReSharper_GotoPrevErrorInSolution<CR>
#endif

nmap <leader>xz :vsc Debug.StartWithoutDebugging<CR>
nmap <leader>xx :vsc Debug.StopDebugging<CR>

nmap <leader>dd :vsc Debug.EnableBreakpoint<CR>
nmap <leader>dp :vsc EditorContextMenus.CodeWindow.Breakpoint.InsertBreakpoint<CR>
nmap <leader>dt :vsc EditorContextMenus.CodeWindow.Breakpoint.InsertTracepoint<CR>
nmap <leader>de :vsc EditorContextMenus.CodeWindow.Breakpoint.BreakpointActions<CR>
nmap <leader>dx :vsc EditorContextMenus.CodeWindow.Breakpoint.DeleteBreakpoint<CR>
nmap <leader>dX :vsc Debug.DeleteAllBreakpoints<CR>
nmap <leader>do :vsc Debug.EnableAllBreakpoints<CR>
nmap <leader>dO :vsc Debug.DisableAllBreakpoints<CR>

nmap sr :vsc Debug.StepOver<CR>
nmap st :vsc Debug.StepInto<CR>
nmap sa :vsc Debug.StepOut<CR>
nmap sz :vsc Debug.Start<CR>
nmap sx :vsc Debug.StopDebugging<CR>
nmap sc :vsc Debug.ShowNextStatement<CR>
#ifdef RESHARPER
map sd :vsc ReSharper.ReSharper_GotoBreakpoints<CR>
#endif

nmap sw :vsc Debug.QuickWatch<CR>
nmap sn :vsc Debug.Breakpoints<CR>
nmap se :vsc Debug.Callstack<CR>
nmap si :vsc Debug.Immediate<CR>
nmap so :vsc View.Output<CR>:vsc Window.ActivateDocumentWindow<CR>
nmap s,o :vsc Edit.ClearOutputWindow<CR>
nmap sl :vsc Debug.Autos<CR>
nmap su :vsc Debug.Locals<CR>
nmap sy :vsc Debug.Watch1<CR>

#ifdef RESHARPER
nmap <leader>tc :vsc ReSharper.ReSharper_UnitTestRunFromContext<CR>
#endif

nmap <leader>wh :vsc Window.ApplyWindowLayout1<CR>
nmap <leader>wo :vsc View.Output<CR>:vsc Window.ActivateDocumentWindow<CR>
nmap <leader>w,o :vsc Edit.ClearOutputWindow<CR>
#ifdef RESHARPER
nmap <leader>wi :vsc ReSharper.ReSharper_ShowInspectionWindow<CR>
nmap <leader>ws :vsc ReSharper.ReSharper_ShowFindResults<CR>
#else
nmap <leader>wi :vsc View.CallHierarchy<CR>
#endif

#ifdef RESHARPER
nmap <leader>vh :vsc ReSharper.ReSharper_HighlightUsages<CR>
nmap <leader>vc :vsc ReSharper_CancelHighlightUsages<CR>
#endif

nmap <leader>qq :vsc File.Exit<CR>

nmap <leader>co :vsc Window.NewWindow<CR>:e ~\.vsvimrc.h<CR>
nmap <leader>cO :vsc Window.NewWindow<CR>:e ~\.vsvimrc<CR>
#ifdef RESHARPER
nmap <leader>cr :!"clang -E -P -DRESHARPER -Wno-invalid-pp-token ~/.vsvimrc.h > ~/.vsvimrc"<CR>:source ~\.vsvimrc<CR>:echo "~/.vsvimrc was regenerated and reloaded"<CR>
#else
nmap <leader>cr :!"clang -E -P -Wno-invalid-pp-token ~/.vsvimrc.h > ~/.vsvimrc"<CR>:source ~\.vsvimrc<CR>:echo "~/.vsvimrc was regenerated and reloaded"<CR>
#endif
nmap <leader>cR :source ~\.vsvimrc<CR>:echo "~/.vsvimrc was reloaded"<CR>

""" Unity related settings
nmap <leader>du :vsc Debug.AttachUnityDebugger<CR>
