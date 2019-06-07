param ([string] $file=$(throw "Please specify a filename."))
(Get-Command $file).Definition