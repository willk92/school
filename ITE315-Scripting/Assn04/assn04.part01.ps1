# Convert Strihttps://social.technet.microsoft.com/wiki/contents/articles/25071.powershell-tip-converting-string-to-character-array.aspxng into ASCII
# Source: 

Write-Host "$args"

$args.ToCharArray() | %{[int][char]$_}