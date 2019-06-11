# Convert String to ASCII
# Source: https://social.technet.microsoft.com/wiki/contents/articles/25071.powershell-tip-converting-string-to-character-array.aspxng into ASCII

Write-Host "$args"

$args.ToCharArray() | %{[int][char]$_}